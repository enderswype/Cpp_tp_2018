#include <iostream>
#include <fstream>
#include <math.h>

// jeu de données (poids, taille) 
// pour un ensemble de 50 femmes 
// et 50 hommes
double data[] = {
  0,149.633,46.3073,
  0,165.684,64.0963,
  0,160.957,59.4404,
  0,163.779,58.1386,
  0,156.954,58.8688,
  0,167.559,71.1254,
  0,159.64,52.15,
  0,166.756,74.8816,
  0,157.201,50.6563,
  0,161.742,47.2431,
  0,172.977,75.5587,
  0,156.969,48.1876,
  0,160.964,58.1144,
  0,149.596,46.1232,
  0,148.433,44.5402,
  0,154.457,57.5689,
  0,178.127,68.6089,
  0,158.134,52.5257,
  0,156.807,48.9284,
  0,160.171,66.0396,
  0,158.209,63.2875,
  0,157.042,55.6867,
  0,168.523,71.388,
  0,165.914,65.789,
  0,167.904,67.4255,
  0,163.899,60.184,
  0,143.632,38.498,
  0,159.358,62.8374,
  0,156.426,62.3361,
  0,157.542,56.5203,
  0,165.891,63.625,
  0,155.461,49.1204,
  0,170.244,68.1394,
  0,152.936,53.9954,
  0,162.408,63.2754,
  0,160.929,56.9782,
  0,161.76,60.0036,
  0,153.134,59.168,
  0,161.055,58.4456,
  0,154.004,49.7689,
  0,171.129,66.2362,
  0,169.857,72.0567,
  0,152.52,51.9842,
  0,162.952,60.3916,
  0,161.193,58.4922,
  0,170.799,69.8823,
  0,168.183,63.0509,
  0,164.32,62.9056,
  0,168.146,81.9648,
  0,167.268,67.6402,
  1,187.571,109.723,
  1,174.706,73.624,
  1,188.24,96.4993,
  1,182.197,99.8113,
  1,177.5,93.6003,
  1,170.823,69.0434,
  1,174.714,83.4297,
  1,173.605,76.1917,
  1,170.228,79.8016,
  1,161.179,70.9429,
  1,180.836,84.644,
  1,181.968,96.953,
  1,164.506,75.809,
  1,175.979,85.9328,
  1,175.879,84.5665,
  1,171.82,78.104,
  1,183.943,88.9185,
  1,162.495,78.4199,
  1,176.886,84.3623,
  1,172.557,82.7487,
  1,172.504,78.979,
  1,176.376,89.691,
  1,168.019,67.6651,
  1,191.023,103.766,
  1,172.449,73.4862,
  1,173.086,87.2472,
  1,175.488,83.6598,
  1,184.914,93.8173,
  1,171.25,79.477,
  1,173.981,70.0098,
  1,174.29,85.0531,
  1,188.046,96.5761,
  1,181.682,88.4666,
  1,175.718,93.0713,
  1,176.726,92.6088,
  1,178.818,87.501,
  1,175.453,89.5807,
  1,170.672,83.3767,
  1,167.151,74.3232,
  1,163.333,73.9858,
  1,172.655,78.0807,
  1,183.361,88.019,
  1,165.787,76.485,
  1,167.869,73.1173,
  1,171.476,74.6899,
  1,178.066,85.6952,
  1,173.36,84.8507,
  1,183.319,94.8345,
  1,175.717,87.0977,
  1,185.091,95.865
};


const auto m = 100;

auto hypothesis(double X[3], double theta[3])
{
	auto h_theta = theta[0] + theta[1]*X[1] + theta[2]*X[2];
	
	return h_theta;
}

auto computeCost(double X[m][3], double Y[m], double theta[3]) 
{
  auto J = 0.0;
  for (int i = 0; i < m; i++)
  {
		J += pow((hypothesis(X[i], theta) - Y[i]), 2);
  }
  return J/(2*m);
}


void gradientDescent(double x[m][3], double y[m], double theta[3], double alpha, int iteration)
{	auto c = alpha/m;
	std::ofstream file("cost.txt");
	
	for (double k = 0; k < iteration; k++)
	{	
		double U0 = 0, U1 = 0, U2 = 0;
		
		for (int i = 0; i < m; i++)
	{
			auto h = hypothesis(x[i], theta) - y[i];
			U0 += c*h;
			U1 += c*h*x[i][1];
			U2 += c*h*x[i][2];
		

	}
	theta[0] -= U0;
	theta[1] -= U1;
	theta[2] -= U2;
  file <<k<<" "<<computeCost(x, y, theta)<<std::endl;
	}

}

int main()
{
  double X[m][3], Y[m];
  
  for (int i = 0; i < m; i++)
  {		X[i][0] = 1;
		X[i][1]	= data[3*i];
		X[i][2] = data[3*i+1];
		Y[i] = data[3*i+2];
  }
  
  std::cout << "recopie de data dans les vecteurs x et y" << std::endl;

  std::cout << "recherche des paramètres theta optimaux" << std::endl<<std::endl;

  double theta[] = {1.0, 2.0, 3.0};

  std::cout<<"hypothèse avec theta["<<theta[0]<<","<<theta[1]<<","<<theta[2]<<"] = "<<hypothesis(X[11], theta)<<std::endl;
  std::cout<<"computeCost : "<<computeCost(X, Y, theta)<<std::endl<<std::endl;
  theta[0] = 2.0;
  theta[1] = 2.5;
  theta[2] = 3.5;
  std::cout<<"hypothèse avec theta["<<theta[0]<<","<<theta[1]<<","<<theta[2]<<"] = "<<hypothesis(X[22], theta)<<std::endl;
  std::cout<<"computeCost : "<<computeCost(X, Y, theta)<<std::endl<<std::endl;
  theta[0] = 0.5;
  theta[1] = 2.9;
  theta[2] = 3.9;
  std::cout<<"hypothèse avec theta["<<theta[0]<<","<<theta[1]<<","<<theta[2]<<"] = "<<hypothesis(X[33], theta)<<std::endl;
  std::cout<<"computeCost : "<<computeCost(X, Y, theta)<<std::endl<<std::endl;
  theta[0] = 4.9;
  theta[1] = 2.2;
  theta[2] = 1.1;
  std::cout<<"hypothèse avec theta["<<theta[0]<<","<<theta[1]<<","<<theta[2]<<"] = "<<hypothesis(X[44], theta)<<std::endl;
  std::cout<<"computeCost : "<<computeCost(X, Y, theta)<<std::endl<<std::endl;
  theta[0] = 0.0;
  theta[1] = 0.0;
  theta[2] = 0.0;

	double moy = 0.0;
	
	for (int i = 0; i < m; i++)
	{	moy += X[i][2];
	}
	moy /= m;
	
	std::cout<<"moyenne taille hommes et femmes confondu : "<<moy<<std::endl<<std::endl;
	
	auto ecart = 0.0, temp = 0.0;
	
	for (int i = 0; i < m; i++)
	{	temp += pow((X[i][2] - moy),2);
	}
	ecart = sqrt(temp/(m - 1));
	
	std::cout<<"ecart type : "<<ecart<<std::endl<<std::endl;
	
	//normzlisation
	for (int i = 0; i < m; i++)
	{
		X[i][2] = (X[i][2] - moy)/ecart;

	}

  auto iterations = 50;
  auto alpha = 0.1;

  gradientDescent(X, Y, theta, alpha, iterations); 
    
std::cout << "paramètre theta obtenu avec l'application de la fonction du gradient descendant:"<<std::endl<< "["<< theta[0] << ","<< theta[1] <<","<<theta[2]<< "]" << std::endl<<std::endl;
	
	double t1[] = {1, 0, (150 - moy)/ecart}, t2[] = {1, 0, (175 - moy)/ecart}, t3[] = {1, 1, (168 - moy)/ecart}, t4[] = {1, 1, (195 - moy)/ecart};
	
  // std::cout<<t1[2]<<" "<<t2[2]<<" "<<t3[2]<<" "<<t4[2]<<" "<<std::endl;
  // std::cout<<theta[0]<<" "<<theta[1]<<" "<<theta[2]<<" "<<std::endl<<std::endl;

    std::cout<<"Pour une femme d’une taille de 150cm, on predit un poids de : "<<hypothesis(t1, theta)<<std::endl;
    std::cout<<"Pour une femme d’une taille de 175cm, on predit un poids de : "<<hypothesis(t2, theta)<<std::endl; 
    std::cout<<"Pour un homme d’une taille de 168cm, on predit un poids de : "<<hypothesis(t3, theta)<<std::endl;
    std::cout<<"Pour un homme d’une taille de 195cm, on predit un poids de : "<<hypothesis(t4, theta)<<std::endl;


  return 0;
}
