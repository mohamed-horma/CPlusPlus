#include <iostream>
#include "../include/book.h"
#include "../include/logical.h"


int main(){
    // int page;
    //test de la fonction lit_au_clavier
    /*
    page = lit_au_clavier();
    std::cout << "le nombre de page est : " << page << std::endl;
    */
    //test de la fonction lit_au_clavier avec un pointeur
    /*
    int page2;
    int *p=&page2;
    lit_au_clavier(p);
    std::cout << "le nombre de page est : " << page2 << std::endl;
    */

    //test de la fonction lit_au_clavier avec un valeur passé en argument
    /* page = 5;
    LitParValeur::lit_au_clavier(page);
    std::cout << "le nombre de page est : " << page  << std::endl;
    */

    //test la finction qui modifie son argument qui est passé par référence.
    /*
     LitParRefe::lit_au_clavier(page);
     std::cout << "le nombre de page est : " << page << std::endl;
    */

    //test de la fonction  lit_au_clavier_Book
    //Book book = lit_au_clavier_Book();
/* 
    int numberOfBooks;
    std::cout << "Entrez le nombre de livres : ";
    std::cin >> numberOfBooks;

    Book* books = new Book[numberOfBooks];
    for(int i=0; i<numberOfBooks; i++){
        std::cout << "livre " << i+1 << std::endl;
         //books[i] = lit_au_clavier_Book(); --- IGNORE ---
        books[i] = lit_au_clavier_Book();
    }
    std::cout << "Avant échange :" << std::endl;
    affiche_livres(books, numberOfBooks);
    Book& longest = livre_le_plus_long(books, numberOfBooks);
    Book& shortest = livre_le_plus_court(books, numberOfBooks);
    
    echange_nombre_de_pages(shortest, longest);
    std::cout << "Après échange :" << std::endl;
    affiche_livres(books, numberOfBooks); */
    
    //Question 3
    /*
    std::cout << "Test de la fonction echange_nombre_de_pages question3:" << std::endl;
    Book b1 = lit_au_clavier_Book();
    Book b2 = lit_au_clavier_Book();
    echange_nombre_de_pages(b1, b2);
    affiche_un_livre(b1);
    affiche_un_livre(b2);
    */
   
    //test de la fonction logical_gate
    /* std::cout << "Test de la fonction logical_gate :" << std::endl;

    std::cout << "false, false : " << logical_gate(false, false) << std::endl;
    std::cout << "false, true : " << logical_gate(false, true) << std::endl;
    std::cout << "true, false : " << logical_gate(true, false) << std::endl;
    std::cout << "true, true : " << logical_gate(true, true) << std::endl; 
     */

   return 0;
}
