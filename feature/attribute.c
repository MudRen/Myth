// attribute.c

#include <dbase.h>
#include <skill.h>
/*
 str:���--strength        unarmed
 con:����--constitution    force
 int:����--intelligence    literate
 spi:����--spirituality    spells
 cps:����--composure       dodge
 per:��ò--personality
 kar:��Ե--karma
 cor:��ʶ--courage
*/

int query_str()
{
    int final;

    final = (int)query("str")
          + query_temp("apply/strength") + query("gift_modify/str");

    if ((int)query_skill("unarmed", 1) > 20)
        final += ((int)query_skill("unarmed", 1) - 20) / 10;

    return final;
}

int query_con()
{
    int final;

    final = (int)query("con")
          +query_temp("apply/constitution") + query("gift_modify/con");

    if ((int)query_skill("force", 1) > 20)
        final += ((int)query_skill("force",1)-20)/10;

    return final;
}

int query_int()
{
    int final;

    final = (int)query("int")
          + query_temp("apply/intelligence") + query("gift_modify/int");

    if ((int)query_skill("literate", 1) > 20)
        final += ((int)query_skill("literate",1)-20)/10;

    if(final>40) final=40; 

    return final;   
}

int query_spi()
{
    int final;

    final = (int)query("spi")
          + query_temp("apply/spirituality") + query("gift_modify/spi");

    if ((int)query_skill("spells",1)>20)
        final += ((int)query_skill("spells",1)-20)/10;

    if (final>60) final=60; 

    return final;
}

int query_cps()
{
    int final;

    final= (int)query("cps") //+ (int)query("force_factor") / 2
         + query_temp("apply/composure") + query("gift_modify/cps");

    if ((int)query_skill("dodge",1)>20)
        final += ((int)query_skill("dodge",1)-20)/10;

//    if(final>40) final=40;

    return final;
}

int query_per()
{
    int final;

    final = (int)query("per")
          + query("gift_modify/per") + query_temp("apply/personality");

    if (final>80) final=80;

    return final;
}

int query_kar()
{
    int final;

    final = (int)query("kar") + query_temp("apply/karma") 
          + query("gift_modify/kar")+ (int)query("donation")/1000000;

    if (final > 40) final=40;
    return final;
}

int query_cor()
{
    int final;

    final = (int)query("cor") + (int)query("bellicosity") / 50
          + query_temp("apply/courage") + query("gift_modify/cor");

    return final;
}
