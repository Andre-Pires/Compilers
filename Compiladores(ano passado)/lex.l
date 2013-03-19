%{
	int num_linhas = 0;
	int num_caracteres = 0;	
	int num_comentarios = 0;	
%}


%x comentario_operacional


%%	   
           

"//"[^\n]"\n" {++num_linhas; /*Comentário de uma linha*/ }

<comment>"\n" {++num_linhas; BEGIN(INITIAL); /* eat up '*'s not followed by '/'s */}   
           
"<<" BEGIN comment; 


%%
