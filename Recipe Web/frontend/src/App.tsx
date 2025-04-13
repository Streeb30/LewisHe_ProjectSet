import "./App.css";
import RecipeCard from "./components/RecipeCard";
import RecipeModal from './components/RecipeModal';
import React, { useState, useEffect, FormEvent, useRef } from 'react';
import { searchRecipes } from './API';
import { getFavoriteRecipes } from './API';
import { addFavoriteRecipe } from './API';
import { removeFavoriteRecipe } from './API';
import { Recipe } from './types';
import { AiOutlineSearch } from 'react-icons/ai';

type Tabs = "search" | "favorites";

const App = () => {
  const [selectedTab, setSelectedTab] = useState<Tabs>("search");
  const [searchTerm, setSearchTerm] = useState<string>("");
  const [recipes, setRecipes] = useState<Array<Recipe>>([]);
  const [selectedRecipeId, setSelectedRecipeId] = useState<string | null>(null);
  const [favoriteRecipes, setFavoriteRecipes] = useState<Array<Recipe>>([]);
  const pageNumber = useRef(1);

  const handleSearchSubmit = async (event: FormEvent) => {
    event.preventDefault();
    try {
      const data = await searchRecipes(searchTerm, 1);
      setRecipes(data.results);
      pageNumber.current = 1;
    } catch (error) {
      console.error('Error fetching recipes:', error);
    }
  };

  const handleViewMoreClick = async () => {
    try {
      const nextPage = pageNumber.current + 1;
      const nextRecipes = await searchRecipes(searchTerm, nextPage);
      setRecipes((prevRecipes) => [...prevRecipes, ...nextRecipes.results]);
      pageNumber.current = nextPage;
    } catch (error) {
      console.error(error);
    }
  };

  const handleRecipeClick = (recipeId: string) => {
    setSelectedRecipeId(recipeId);
  };

  const handleCloseModal = () => {
    setSelectedRecipeId(null);
  };

  const handleFavoriteClick = async (recipe: Recipe) => {
    try {
      await addFavoriteRecipe(recipe);
      setFavoriteRecipes([...favoriteRecipes, recipe]);
    } catch (error) {
      console.error('Error adding favorite recipe:', error);
    }
  };

  const handleRemoveFavoriteClick = async (recipe: Recipe) => {
    try {
      await removeFavoriteRecipe(recipe);
      const updatedRecipes = favoriteRecipes.filter(
        (favRecipe) => favRecipe.id !== recipe.id
      );
      setFavoriteRecipes(updatedRecipes);
    } catch (error) {
      console.error('Error removing favorite recipe:', error);
    }
  };

  useEffect(() => {
    const fetchFavoriteRecipes = async () => {
      try {
        const favoriteRecipes = await getFavoriteRecipes();
        setFavoriteRecipes(favoriteRecipes.results);
      } catch (error) {
        console.error(error);
      }
    };

    fetchFavoriteRecipes();
  }, []);

  return (
    <div className="app-container">
      <div className="header">
        <img src="/green_grass.jpg" alt="Grass" />
        <div className="title">Recipes Cyclopedia</div>
      </div>
      <div className="tabs">
        <h1 className={selectedTab === 'search' ? 'tab-active' : ''} onClick={() => setSelectedTab("search")}>Recipe Search</h1>
        <h1 className={selectedTab === 'favorites' ? 'tab-active' : ''} onClick={() => setSelectedTab("favorites")}>Favorites</h1>
      </div>
      

      {selectedTab === 'search' && (
        <div>
          <form onSubmit={handleSearchSubmit}>
            <input
              type="text"
              required
              placeholder="Enter a search term"
              value={searchTerm}
              onChange={(event) => setSearchTerm(event.target.value)}
            />
            <button type="submit">
              <AiOutlineSearch size={40} />
            </button>
          </form>
          {recipes.length === 0 && <p>No recipes found.</p>}         
          <div className="recipe-grid">
            {recipes.map((recipe) => {
              const isFavorite = favoriteRecipes.some(
                (favRecipe) => favRecipe.id === recipe.id
              );
              return (
                <RecipeCard
                  key={recipe.id}
                  recipe={recipe}
                  onClick={() => handleRecipeClick(recipe.id)}
                  onFavoriteClick={() => isFavorite ? handleRemoveFavoriteClick(recipe) : handleFavoriteClick(recipe)}
                  isFavorite={isFavorite}
                />
              );
            })}
          </div>
          {recipes.length > 0 && (
            <button className="view-more" onClick={handleViewMoreClick}>
              View More
            </button>
          )}
          {selectedRecipeId && (
            <RecipeModal recipeId={selectedRecipeId} onClose={handleCloseModal} />
          )}
        </div>
      )}
      
      {selectedTab === 'favorites' && (
        <div>
          {favoriteRecipes.length === 0 && <p>No favorite recipes found.</p>}
          <div className="recipe-grid">
            {favoriteRecipes.map((recipe) => (
              <RecipeCard
                key={recipe.id}
                recipe={recipe}
                onClick={() => handleRecipeClick(recipe.id)}
                onFavoriteClick={() => handleRemoveFavoriteClick(recipe)}
                isFavorite={true}
              />
            ))}
          </div>
        </div>
      )}
    </div>
  );
};

export default App;
