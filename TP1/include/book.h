#ifndef B_H
#define B_H

struct Book{
    char title[50];
    int numberOfPages;
};
namespace LitParValeur{
    void lit_au_clavier(int p);
}
namespace LitParRefe{
    void lit_au_clavier(int& p);
}

int lit_au_clavier();

void lit_au_clavier(int* p);

void lit_au_clavier_title(char* title);

Book lit_au_clavier_Book();

void affiche_un_livre(Book b);

void affiche_livres(Book* books, int numberOfBooks);

void echange_nombre_de_pages(Book& b1, Book& b2);

Book& livre_le_plus_long(Book* books, int size);

Book& livre_le_plus_court(Book* books, int size);


#endif
