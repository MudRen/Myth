#include <ansi.h>
inherit F_SAVE;
inherit ITEM;
int do_zhai(string);
void init();
mapping idget = ([]);


void create()
{
        set_name(HIC "Ê¥µ®Àñ"HIR"Îï"HIG"Ê÷" NOR, ({ "liwu tree", "tree"}) );
        set_weight(6000);
        
                set("long", "ÐÇµÆÉÁË¸ÃÀÀö²ÓÀÃµÄÀñÎïÊ÷£¬ÉÏÃæÓÐºÜ¶àÐ¡ÀñÎï£¬ÄãÈÌ²»×¡È¥Õª£¨zhai liwu)¡£\n
                    @* .¡î  £ª/ * . ¡î/ £ª¡£   \n
                       ¨¨Ž¡£       ¨¨Ž¡£     \n
                      ¨¡ï¨Ž¡£     ¨¡ï¨Ž¡£    \n
                     ¨¡ö¡ö¨Ž¡£   ¨¡ö¡ö¨Ž¡£   \n
                    ¨¡ö¡ö¡ö¨Ž¡£ ¨¡ö¡ö¡ö¨Ž¡£  \n
                    ¦ñ¦ñ||¦ñ¦ñ !!¦ñ¦ñ||¦ñ¦ñ    \n
                                                \n
  ×£ÄãÍòÊÂÈçÒâ£¬ÐÄÏëÊÂ³É¡£           ¨… ¡ï¡à      \n
             ¡¡¡¡¡¡£®£®£®£®¨…¨…£®..£®¨€¨… ¡î ¡ï¡ß ....k \n
             ¡¡¡¡¡¡¨¨€¨|¨|¨€¨€¨|¨|¨€¨€¨|¨|¨|¨|¨|¨€¨€¨€¨ \n
             ¡¡¡¡¡¡£®¨¨€¨€¨€¨€¨€¨€¨€¨€¨€¨€¨€¨€¨€¨€¨€¨  \n
             ¡¡¡«¡«¡«¡«¨¨€¨€¨€¨€¨€¨€¨€¨€¨€¨€¨€¨€¨€¨¡«¡«¡«¡« \n
                                                                ¡
                ");
      
         set("no_clean_up", 0);
       
         set("is_monitored",1);
         set("no_get",1);
         setup();
         restore();
         
}

void init()
{
    set("no_get",1);
    set("no_give",1);
    set("no_drop",1);
    set("no_sell",1);
        add_action("do_zhai", "zhai");
}

int do_zhai(string arg)
{
        object ob,me;
        string id,*objs;
        int tt;
        objs=({
               "/u/stey/obj/ice",
               "/u/stey/obj/zhou",
               "/u/stey/obj/hongbao",
               "/d/wiz/obj/card",
               "/d/wiz/obj/qq",
       
                     });
        me = this_player();

        if (arg!="liwu" )   return 0;

        me = this_player();
        if (!userp(me))     return notify_fail("Ê²Ã´¶«Î÷!");
        if(me->query("sen")<100)   return notify_fail("ÄãÁôµã¾«Éñ°É!");

        if (me->query("combat_exp") < 200000 && (int)me->query("mud_age")<18000)
                            return notify_fail("ÄãÊÇ´óÃ×Âð?²»ÊÇ£¿ÎÒ¿´Í¦Ïó!");
         id=me->query("id");
        me->start_busy(3);
        me->add("sen",-50);
        if(!undefinedp(idget[id]) && (idget[id]+1800) > time())
                            return notify_fail("Äã¸ÕÄÃÁËÀñÎï£¬²»¿ÉÌ«Ì°Ó´£¬µÈµÈÔÙÀ´°É£¡\n");
        this_object()->restore();
        idget[id]=time();
        this_object()->save();
        ob=new(objs[random(sizeof(objs))]);

        if(ob->move(me))
         {
        message_vision(HIY"ÐÂ"+HIC"´º"+HIR+"¡ï"+HIB+"¿ì"+HIW+"ÀÖ£¡\n"+me->query("name")+"´ÓÀñÎïÊ÷ÄÃµ½ÁËÒ»"+ob->query("unit")+ob->query("name")+"¡£ \n"NOR, me);
                             ob->set("owner",id);
                             ob->set("owner_id",id);
                             ob->set("ownerid",id);
                             ob->set("no_put",1);
                             ob->set("no_give",1);
                             ob->set("no_get",1);
                             ob->set("no_bag",1);
                             ob->set("no_sell",1);
                             ob->set("no_zm",1);
         }else if (ob){destruct(ob);}
        return 1;

}

string query_save_file()
{
        return DATA_DIR+"liwutree.o";
}

void set_save_file(string str)
{
        set("save_file",str);
}

