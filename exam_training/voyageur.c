// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   voyageur.c                                         :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: cw3l <cw3l@student.42.fr>                  +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/03/12 21:29:06 by cw3l              #+#    #+#             */
// /*   Updated: 2025/03/13 08:55:26 by cw3l             ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>

// #define N 4  // Nombre de villes (ajuste selon ton besoin)

// // Structure pour stocker les coordonnées des villes
// typedef struct {
    
//     double x;
//     double y;
    
// } City;


// void print_matrix(double mat[N][N]) {
//     printf("Matrice des distances :\n");
//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j < N; j++) {
//             printf("%.2f ", mat[i][j]);  // Affichage avec 2 décimales
//         }
//         printf("\n");  // Nouvelle ligne après chaque ligne de la matrice
//     }
//     printf("\n");
// }

// // Fonction pour calculer la distance euclidienne entre deux villes
// double get_euclidean_d(City p1, City p2) {
    
//     double value;
//     value = ((p2.x - p1.x) * (p2.x - p1.x)) + ((p2.y - p1.y) * (p2.y - p1.y));
//     return (sqrt(value));
// }

// // Fonction pour remplir la matrice des distances
// void get_matrice(City cities[], double mat[N][N]) {
//     int i;
//     int j;

//     i = 0;
//     while (i < N)
//     {
//         j = 0;
//         while (j < N)
//         {
//             mat[i][j] =  get_euclidean_d(cities[i],cities[j]);
//             j++;
//         }
//         i++;
//     }
// }

// void ft_swap(int *p1, int *p2)
// {
//     int tmp;

//     tmp = *p1;
//     *p1 = *p2;
//     *p2 = tmp;
    
// }

// void ft_printf_arr(int *arr, int n)
// {
//     int i;

//     i = 0;
//     while (i < n)
//     {
//         printf("%d ", arr[i]);
//         i++;
//     }
//     printf("\n");
    
// }

// void permutation(int arr[], int start, int end) 
// {
//     int i;
    
//     if(start == end)
//     {
//         ft_printf_arr(arr,end);
//     }
//     else
//     {
//         i = start;
//         while (i <= end)
//         {
//             ft_swap(&arr[start], &arr[i]);
//             permutation(arr, start + 1, end);
//             ft_swap(&arr[start], &arr[i]);
//             i++;
//         }
        
//     }
// }

// // Fonction pour calculer la distance totale d'un chemin donné
// double get_parcour_value(int arr[], int n, City cities[], double mat[N][N]) {
//     // À implémenter
//     return 0.0;
// }

// // Fonction pour trouver le chemin optimal en force brute
// void tsp_brute_force(City cities[], double mat[N][N]) {
//     int arr[N];
//     int i;

//     i = 0;
//     while (i < N)
//     {
//         arr[i] = i;
//         i++;
//     }
    
//     permutation(arr,0,N);
// }

// // Fonction principale
// // int main() {
    
// //     City cities[N] = {
// //         {0.0, 0.0}, {1.0, 0.0}, {2.0, 0.0}, {0.0, 1.0},
// //         //{1.0, 1.0}, {2.0, 1.0}, {1.0, 2.0}, {2.0, 2.0}
// //     };

// //     double mat[N][N];  // Matrice des distances

// //     // Étape 1 : Construire la matrice des distances
// //     get_matrice(cities, mat);
    
// //     // Étape 2 : Trouver le chemin optimal (force brute ou autre)
// //     tsp_brute_force(cities, mat);

// //     return 0;
// // }
