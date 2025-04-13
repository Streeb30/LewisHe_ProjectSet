require('dotenv').config();
import express from "express";
import cors from "cors";
import * as RecipeAPI from "./recipe-api";
import { PrismaClient } from "@prisma/client";
import { getFavoriteRecipesByIds } from "./recipe-api";

const prismaClient = new PrismaClient();
const app = express();
app.use(express.json());
app.use(cors());

app.get("/api/recipes/search", async (req, res) => {
  const searchTerm = req.query.searchTerm as string || '';
  const page = parseInt(req.query.page as string) || 1;

  try {
    const results = await RecipeAPI.searchRecipes(searchTerm, page);  // Ensure that this matches how you imported it
    return res.json(results);
  } catch (error) {
    console.error('Failed to fetch recipes:', error);
    return res.status(500).json({ error: 'Failed to fetch recipes' });
  }
});

app.get("/api/recipes/:id/summary", async (req, res) => {
  const recipeId = req.params.id;
  try {
    const summary = await RecipeAPI.getRecipeSummaryFromAPI(recipeId);
    res.json(summary);
  } catch (error) {
    console.error('Error fetching recipe summary:', error);
    res.status(404).json({ error: 'Recipe summary not found' });
  }
});

app.post("/api/recipes/favorite", async (req, res) => {
  const { recipeId } = req.body;
  try {
    const favoriteRecipe = await prismaClient.favoriteRecipe.create({
      data: { recipeId },
    });
    res.status(201).json(favoriteRecipe);
  } catch (error) {
    console.error(error);
    res.status(500).json({ error: "Oops, something went wrong." });
  }
});

app.get('/api/recipes/favorite', async (req, res) => {
  try {
    const favoriteRecipes = await prismaClient.favoriteRecipe.findMany();
    const recipeIds = favoriteRecipes.map(recipe => recipe.recipeId.toString());

    if (recipeIds.length > 0) {

      const detailedRecipes = await getFavoriteRecipesByIds(recipeIds);
      res.json(detailedRecipes);
    } else {
      res.json({ results: [] });
    }
  } catch (error) {
    console.error('Error fetching favorites:', error);
    res.status(500).json({ error: 'Error fetching favorites' });
  }
});

app.delete("/api/recipes/favorite", async (req, res) => {
  const { recipeId } = req.body;

  try {
    const favorite = await prismaClient.favoriteRecipe.delete({
      where: {
        recipeId,
      },
    });
    return res.json(favorite);
  } catch (error) {
    console.error('Failed to remove favorite recipe:', error);
    return res.status(500).json({ error: 'Failed to remove favorite recipe' });
  }
});

app.listen(5000, () => {
  console.log("Server running on localhost:5000");
});