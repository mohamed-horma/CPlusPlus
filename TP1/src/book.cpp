#include <iostream>
#include "../include/book.h"
#include <limits>

/*
*@return void as number of pages is passed by value
*/
namespace LitParValeur{    
    void lit_au_clavier(int page){
        std::cout << "Entrez le nomre de pages : " ; 
        std::cin >>page;       
        while(page<2 || page>200){
            std::cout << "Entrez le nomre de pages : " ;
            std::cin >>page; 
        }   
    }    
}
/*
*@return void as number of pages is passed by reference 
*
*/
namespace LitParRefe{
    void lit_au_clavier(int& page){
        std::cout << "Entrez le nomre de pages : " ; 
        std::cin >>page;       
        while(page<2 || page>200){
            std::cout << "Entrez le nomre de pages :" ;
            std::cin >>page; 
        }           
    }
}
/*
*@return int as number of pages
*
*/

int lit_au_clavier(){
        int i;
        std::cout << "Entrez le nomre de pages : " ; 
        std::cin >> i;       
        while(i<2 || i>2000){
            std::cout << "Entrez le nomre de pages : " ;
            std::cin >>i; 
       } 
    
        return i;
}
/*
*
*@return void as number of pages is passed by pointer
*/

void lit_au_clavier(int* page){
        std::cout << "Entrez le nomre de pages : " ; 
        std::cin >>*page;       
        while(*page<2 || *page>200){
            std::cout << "Entrez le nomre de pages : " ;
            std::cin >>*page; 
        }   
}

/*
*
*
*@return char* as title of the book
*/
void lit_au_clavier_title(char* title){
    std::cout << "Entrez le titre du livre : ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.getline(title,50);
    
}
/*
*
*@return Book
*/
Book lit_au_clavier_Book(){
    Book b;
    b.numberOfPages = lit_au_clavier();
    lit_au_clavier_title(b.title);
    return b;
}

/*
*@return void as it just displays the book information
*/
void affiche_un_livre(Book b){
    std::cout << "Livre : " << b.title 
              << " ,Pages : " << b.numberOfPages <<std::endl;
}

/*
*@return void as it just displays the books information
*/
void affiche_livres(Book* books, int size){
    for(int i=0; i<size; i++){
        affiche_un_livre(books[i]);
    }
}

/*
*@return void as it just exchanges the number of pages of two books
*/

void echange_nombre_de_pages(Book& b1, Book& b2){
    int temp = b1.numberOfPages;
    b1.numberOfPages = b2.numberOfPages;
    b2.numberOfPages = temp;    
}
/*
*@return Book the book with the most number of pages
*/
Book& livre_le_plus_long(Book* books, int size){
    int maxIndex = 0;
    for(int i=0; i<size; i++){
        if(books[i].numberOfPages > books[maxIndex].numberOfPages){
            maxIndex = i;
        }
    }
    return books[maxIndex];
}
/*
*@return Book the book with the least number of pages
*/

Book& livre_le_plus_court(Book* books, int size){
    int minIndex = 0;
    for(int i=0; i<size; i++){
        if(books[i].numberOfPages < books[minIndex].numberOfPages){
            minIndex = i;
        }
    }
    return books[minIndex];
}


         