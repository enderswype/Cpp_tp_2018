#include "vector.hpp"

using namespace ml;

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

int main()
{
  /*auto computeStd = [](double X[m][3], double mu, int i)
  {
    auto sigma = 0.0;
    for(auto j = 0; j < m; ++j) {
    sigma += (X[j][i] - mu)*(X[j][i] - mu);
  }
    return std::sqrt(sigma/(m-1));
  };*/

  /*auto computeStd = [](vector X_taille, double mu)
  {
    auto sigma = 0.0;
    for(auto j = 0; j < m; ++j) {
    sigma += (X_taille[j] - mu)*(X_taille[j] - mu);
  }
    return std::sqrt(sigma/(m-1));
  };*/

  auto computeStd = [](matrix données, double mu)
  {
    auto sigma = 0.0;
    for(auto j = 0; j < m; ++j)
    {
    sigma += (données[j][2] - mu)*(données[j][2] - mu);
    }
    return std::sqrt(sigma/(m-1));
  };
  
  /*auto hypothesis = [](double x[3], double theta[3])
  {
    return theta[0] * x[0] + theta[1] * x[1] + theta[2] * x[2];
  };*/

  auto hypothesis = [](double oui, double sex, double taille, vector theta)
  {
    return theta[0] * oui + theta[1] * sex + theta[2] * taille;
  };

  auto hypothesis_vect = [](vector X_test, vector theta)
  {
    return theta[0] * X_test[0] + theta[1] * X_test[1] + theta[2] * X_test[2];
  };

  /*auto computeCost = [hypothesis](double X[m][3], double y[m], double theta[3])
    {
    auto J = 0.0;
    for(auto i = 0; i < m; ++i) {
      const auto h = hypothesis(X[i], theta) - y[i];
      J += 1.0 / (2.0*m) * h * h;
    }
    return J;
    };*/

    auto computeCost = [hypothesis](vector X_1, vector X_sex, vector X_taille, vector Y_poids, vector theta)
    {
    auto J = 0.0;
    for(auto i = 0; i < m; ++i) {
      std::cout<<"begin "<<i<<std::endl;
      const auto h = hypothesis(X_1[i], X_sex[i], X_taille[i], theta) - Y_poids[i];
      J += 1.0 / (2.0*m) * h * h;
      std::cout<<"end "<<i<<std::endl;
    }
    return J;
    };

  /*auto computeMean = [](double X[m][3], int i)
  {
    auto mu = 0.0;
    for(auto j = 0; j < m; ++j) {
    mu += X[j][i];
    }
    return mu / m;
  };*/

  /*auto computeMean = [](vector X_taille)
  {
    auto mu = 0.0;
    for (int i = 0; i < m; ++i)
    {
      mu += X_taille[i];
    }
    return mu /= m;
  };*/

  auto computeMean = [](matrix données)
  {
    auto mu = 0.0;
    for (int i = 0; i < m; ++i)
    {
      mu += données[i][2];
    }
    return mu /= m;
  };

  /*auto featureNormalize = [](double X[m][3], double mu, double sigma, int i)
  {
    for(auto j = 0; j < m; ++j) {
    X[j][i] = (X[j][i]-mu)/sigma;
    }
  };*/

  auto featureNormalize = [](vector X_taille, double mu, double sigma)
  {
    for(auto j = 0; j < m; ++j) {
    X_taille[j] = (X_taille[j]-mu)/sigma;
    }
  };

  /*auto gradientDescent = [hypothesis, computeCost](double X[m][3], double y[m], double theta[3], double alpha, int iteration)
  {
    std::ofstream file("cost.txt");
  
    for(auto iter = 0; iter<iteration; ++iter) {
    
    double Update[] = { 0.0, 0.0, 0.0 };
    for(auto i = 0; i<m; ++i) {
      const auto h = hypothesis(X[i], theta) - y[i];
      Update[0] = Update[0] + alpha/m * h * X[i][0];
      Update[1] = Update[1] + alpha/m * h * X[i][1];
      Update[2] = Update[2] + alpha/m * h * X[i][2];
    }
    
    theta[0] = theta[0] - Update[0];
    theta[1] = theta[1] - Update[1];
    theta[2] = theta[2] - Update[2];
    
    file << computeCost(X,y,theta) << std::endl;
    }
  };*/

    auto gradientDescent = [hypothesis, computeCost](vector X_1, vector X_sex, vector X_taille, vector Y_poids, vector theta, double alpha, int iteration)
  {
    std::ofstream file("cost.txt");
  
    for(auto iter = 0; iter<iteration; ++iter) {
    
    //double Update[] = { 0.0, 0.0, 0.0 };
    vector Update(3);
    Update = 0.0;
    for(auto i = 0; i<m; ++i) {
      const auto h = hypothesis(X_1[i], X_sex[i], X_taille[i], theta) - Y_poids[i];
      Update[0] += alpha/m * h * X_1[i];
      Update[1] += alpha/m * h * X_sex[i];
      Update[2] += + alpha/m * h * X_taille[i];
    }
    
    theta[0] -= Update[0];
    theta[1] -= Update[1];
    theta[2] -= Update[2];
    
    file << computeCost(X_1[iter], X_sex[iter], X_taille[iter], Y_poids ,theta) << std::endl;
    }
  };
  
  //double X[m][3], y[m];
  /*vector X_1(m);
  vector X_sex(m);
  vector X_taille(m);
  vector Y_poids(m);*/
  matrix données(m, 4);
  
  std::cout << "recopie de data dans les vecteurs x et y" << std::endl;
  
  for(auto i = 0; i < m; ++i) {
    /*X[i][0] = 1.0;
    X[i][1] = data[3*i];
    X[i][2] = data[3*i+1];
    y[i]    = data[3*i+2];*/

    /*X_1[i] = 1.0;
    X_sex[i] = data[3*i];
    X_taille[i] = data[3*i+1];
    Y_poids[i] = data[3*i+2];*/

    données(i, 0) = 1.0;
    données(i, 1) = data[3*i];
    données(i, 2) = data[3*i+1];
    données(i, 3) = data[3*i+2];
  }
  
  //auto mu = computeMean(X,2);
  //auto mu = computeMean(X_taille);
  auto mu = computeMean(données);
  //auto sigma = computeStd(X,mu,2);
  //auto sigma = computeStd(X_taille, mu);
  auto sigma = computeStd(données, mu);

  //std::cout << mu << std::endl;
  std::cout << "moyenne des tailles : "<<mu << std::endl;
  
  std::cout << sigma << std::endl;
  std::cout <<"sigma : "<< sigma << std::endl;
  
  //featureNormalize(X,mu,sigma,2);
  //std::cout<<X_taille<<std::endl;
  featureNormalize(X_taille,mu,sigma);
  //std::cout<<X_taille<<std::endl;
  
  /*{ // verification de l'hypothèse
    double theta1[] = { 1., 2., 3. };
    std::cout << "verification hypothesis(x[11],theta1) = " << hypothesis(X[11],theta1) << std::endl;
    double theta2[] = { 2., 2.5, 3.5 };
    std::cout << "verification hypothesis(x[33],theta2) = " << hypothesis(X[33],theta2) << std::endl;
    double theta3[] = { 0.5, 2.9, 3.9 };
    std::cout << "verification hypothesis(x[55],theta3) = " << hypothesis(X[55],theta3) << std::endl;
    double theta4[] = { 4.9, 2.2, 1.1 };
    std::cout << "verification hypothesis(x[77],theta4) = " << hypothesis(X[77],theta4) << std::endl;
  }*/

  /*{ // verification de la fonction de cout
    double theta1[] = { 1., 2., 3. };
    std::cout << "verification computeCost(x,y,theta1) = " << computeCost(X,y,theta1) << std::endl<< std::endl;
    double theta2[] = { 2., 2.5, 3.5 };
    std::cout << "verification computeCost(x,y,theta2) = " << computeCost(X,y,theta2) << std::endl<< std::endl;
    double theta3[] = { 0.5, 2.9, 3.9 };
    std::cout << "verification computeCost(x,y,theta3) = " << computeCost(X,y,theta3) << std::endl<< std::endl;
    double theta4[] = { 4.9, 2.2, 1.1 };
    std::cout << "verification computeCost(x,y,theta4) = " << computeCost(X,y,theta4) << std::endl<< std::endl;
  }*/

  { // verification de l'hypothèse
    vector theta1(3);
    theta1[0] = 1.0;
    theta1[1] = 2.0;
    theta1[2] = 3.0;
    int i = 11;
    std::cout << "verification hypothesis(x[11],theta1) = " << hypothesis(X_1[i], X_sex[i], X_taille[i], theta1) << std::endl;
    std::cout << "verification computeCost(x,y,theta1) = " << computeCost(X_1[i], X_sex[i], X_taille[i], Y_poids, theta1) << std::endl<<std::endl;
    delete &theta1;
    vector theta2(3);
    theta2[0] = 2.0;
    theta2[1] = 2.5;
    theta2[2] = 3.5;
    i = 33;
    std::cout << "verification hypothesis(x[33],theta2) = " << hypothesis(X_1[i], X_sex[i], X_taille[i], theta2) << std::endl;
    std::cout << "verification computeCost(x,y,theta2) = " << computeCost(X_1[i], X_sex[i], X_taille[i], Y_poids ,theta2) << std::endl<< std::endl;
    delete &theta2;
    vector theta3(3);
    theta3[0] = 0.5;
    theta3[1] = 2.9;
    theta3[2] = 3.9;
    i = 55;
    std::cout << "verification hypothesis(x[55],theta3) = " << hypothesis(X_1[i], X_sex[i], X_taille[i], theta3) << std::endl;
    std::cout << "verification computeCost(x,y,theta3) = " << computeCost(X_1[i], X_sex[i], X_taille[i], Y_poids ,theta3) << std::endl<< std::endl;
    delete &theta3;
    vector theta4(3);
    theta4[0] = 4.9;
    theta4[1] = 2.2;
    theta4[2] = 1.1;
    i = 77;
    std::cout << "verification hypothesis(x[77],theta4) = " << hypothesis(X_1[i], X_sex[i], X_taille[i], theta4) << std::endl;
    std::cout << "verification computeCost(x,y,theta4) = " << computeCost(X_1[i], X_sex[i], X_taille[i], Y_poids ,theta4) << std::endl<< std::endl;
    delete &theta4;
  }
  
  std::cout << "recherche des paramètres theta optimaux" << std::endl;
  
  //double theta[] = { 0.0, 0.0, 0.0 };
  vector theta(3);
  theta = 0.0;
  
  auto iterations = 50;
  auto alpha = 0.1;
  
  //gradientDescent(X, y, theta, alpha, iterations);
  gradientDescent(X_1, X_sex, X_taille, Y_poids, theta, alpha, iterations);
  
  /*std::cout << "paramètre theta obtenu : ["
            << theta[0] << ","
            << theta[1] << ","
            << theta[2] << "]" << std::endl;*/
  std::cout<<"voila theta : "<<theta<<std::endl;
  
  //double x1[] = { 1.0, 0.0, (150-mu)/sigma };
  vector X_test(3);
  X_test[0] = 1.0;
  X_test[1] = 0.0;
  X_test[2] = (150-mu)/sigma;
  auto predict1 = hypothesis_vect(X_test, theta);
  std::cout << "Pour une femme d'une taille de 150cm, on prédit un poids de "
            << predict1 << "kg" << std::endl<<std::endl;

  //double x2[] = { 1.0, 0.0, (175-mu)/sigma };
  X_test[2] = (175-mu)/sigma;
  auto predict2 = hypothesis_vect(X_test, theta);
  std::cout << "Pour une femme d'une taille de 175cm, on prédit un poids de "
            << predict2 << "kg" << std::endl<<std::endl;

  //double x3[] = { 1.0, 1.0, (168-mu)/sigma };
  X_test[1] = 1.0;
  X_test[2] = (168-mu)/sigma;
  auto predict3 = hypothesis_vect(X_test, theta);
  std::cout << "Pour un homme d'une taille de 168cm, on prédit un poids de "
            << predict3 << "kg" << std::endl<<std::endl;

  //double x4[] = { 1.0, 1.0, (195-mu)/sigma };
  X_test[2] = (195-mu)/sigma;
  auto predict4 = hypothesis_vect(X_test, theta);
  std::cout << "Pour un homme d'une taille de 195cm, on prédit un poids de "
            << predict4 << "kg" << std::endl<<std::endl;
  
  return 0;
}
