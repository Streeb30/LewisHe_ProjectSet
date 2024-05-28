const API_KEY = process.env.API_KEY;

export const searchRecipes = async (searchTerm: string, page: number) => {
  if (!API_KEY) {
    throw new Error("API key not found");
  }

  const baseURL = "https://api.spoonacular.com/recipes/complexSearch";
  const url = new URL(baseURL);

  const queryParams = {
    apiKey: API_KEY,
    query: searchTerm,
    number: '10',
    offset: ((page - 1) * 10).toString(),
  };

  url.search = new URLSearchParams(queryParams).toString();

  try {
    const searchResponse = await fetch(url.toString());
    if (!searchResponse.ok) {
      throw new Error(`HTTP Error: ${searchResponse.status}`);
    }
    const resultsJson = await searchResponse.json();
    return resultsJson;
  } catch (error) {
    console.error('Failed to fetch recipes:', error);
    throw error;
  }
};

export const getRecipeSummaryFromAPI = async (recipeId: string) => {
  const response = await fetch(`https://api.spoonacular.com/recipes/${recipeId}/summary?apiKey=${API_KEY}`);
  if (!response.ok) {
    throw new Error(`HTTP error! status: ${response.status}`);
  }
  return response.json();
};

export const getFavoriteRecipesByIds = async (ids: string[]) => {
  if (!API_KEY) {
    throw new Error("API Key not found");
  }
  const url = new URL("https://api.spoonacular.com/recipes/informationBulk");
  url.search = new URLSearchParams({
    apiKey: API_KEY,
    ids: ids.join(","),
  }).toString();

  const response = await fetch(url);
  const json = await response.json();
  return { results: json };
};
