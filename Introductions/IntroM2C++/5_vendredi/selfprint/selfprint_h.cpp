const char c[]="\57\52\40\106\111\116\40\52\57\12\43\151\156\143\154\165\144\145\40\74\143\163\164\144\151\157\76\12\40\151\156\164\40\155\141\151\156\50\51\173\12\40\40\40\40\40\143\157\156\163\164\40\143\150\141\162\40\52\160\75\143\73\12\40\40\40\40\40\160\162\151\156\164\146\50\42\143\157\156\163\164\40\143\150\141\162\40\143\133\135\75\134\42\42\51\73\12\40\40\40\40\40\146\157\162\50\160\75\143\73\52\160\73\53\53\160\51\12\40\40\40\40\40\40\40\40\40\160\162\151\156\164\146\50\42\134\134\45\157\42\54\52\160\51\73\12\40\40\40\40\40\160\162\151\156\164\146\50\42\134\42\73\134\156\42\51\73\12\40\160\162\151\156\164\146\50\42\45\163\42\54\143\51\73\12\40\162\145\164\165\162\156\40\60\73\12\175\12";
/* FIN */
#include <cstdio>
 int main(){
     const char *p=c;
     printf("const char c[]=\"");
     for(p=c;*p;++p)
         printf("\\%o",*p);
     printf("\";\n");
 printf("%s",c);
 return 0;
}