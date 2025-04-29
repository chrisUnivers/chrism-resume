
const getEnv = (key: string, defaultValue?: string): string => {
    
    const value = process.env[key] || defaultValue;
  
    if (value === undefined) {
      throw Error(`environment variable${key}`);
    }
  
    return value;
};
  
export const MONGO_URI = getEnv("MONGO_URI");
export const PORT = getEnv("PORT", "5000");
export const NODE_ENV = getEnv("NODE_ENV", "development");
export const APP_ORIGIN = getEnv("APP_ORIGIN");