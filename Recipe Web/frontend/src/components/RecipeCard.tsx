import React from 'react';
import { Recipe } from '../types';
import { AiOutlineHeart, AiFillHeart  } from "react-icons/ai";
import '../App.css';

interface Props {
  recipe: Recipe;
  onClick: () => void;
  onFavoriteClick: (recipe: Recipe) => void;
  isFavorite: boolean;
}

const RecipeCard: React.FC<Props> = ({ recipe, onClick, onFavoriteClick, isFavorite }) => {
  return (
    <div className="recipe-card" onClick={onClick}>
      <img src={recipe.image} alt={recipe.title} />
      <span onClick={(e) => { e.stopPropagation(); onFavoriteClick(recipe); }}>
        {isFavorite ? <AiFillHeart size={25} color="red" /> : <AiOutlineHeart size={25} />}
      </span>
      <h4>{recipe.title}</h4>
      <p>Recipe Image Location: {recipe.image}</p>
      <p>Recipe Title: {recipe.title}</p>
    </div>
  );
};

export default RecipeCard;
