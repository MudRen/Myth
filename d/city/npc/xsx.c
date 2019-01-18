//By waiwai@sjmd 2000/09/25
 
#include <ansi.h>
inherit NPC;
string tell_fortune();
string fortune1(object me);
string rsg(object me);
string ask_beauty()
{
	object me = this_player();
    object *ob = filter_array(objects(), (: userp($1) && !wiz_level($1) :));
	int no;

	ob = filter_array(ob,
		(: $2->query("per")	< $1->query("per") :), me);
	no = sizeof(ob) + 1;
	return me->name()+RANK_D->query_respect(me)+"µÄÈİÃ²ÔÚÄ¿Ç°ÔÚÏßÍæ¼ÒÖĞÅÅÃûµÚ "
		HIR+chinese_number(no)+" "NOR;
}

string ask_age()
{
	object me = this_player();
    object *ob = filter_array(objects(), (: userp($1) && !wiz_level($1) :));
	int no;

	ob = filter_array(ob,
		(: $2->query("age")*12+$2->query("month")
			< $1->query("age")*12+$1->query("month") :), me);
	no = sizeof(ob) + 1;
	return me->name()+RANK_D->query_respect(me)+"µÄÄêÁäÔÚÄ¿Ç°ÔÚÏßÍæ¼ÒÖĞÅÅÃûµÚ "
		HIR+chinese_number(no)+""NOR;
}

int ask_exp()
{
	object me = this_player();
    object *ob = filter_array(objects(), (: userp($1) && !wiz_level($1) :));
	int no;

	ob = filter_array(ob,
		(: $2->query("combat_exp")	< $1->query("combat_exp") :), me);
	no = sizeof(ob) + 1;

	command("say "+me->name()+RANK_D->query_respect(me)+"µÄÎäÑ§ÔÚÄ¿Ç°ÔÚÏßÍæ¼ÒÖĞÅÅÃûµÚ "
		HIR+chinese_number(no)+""NOR);
	message_vision( "$NÖ¸×Å$nÔŞÌ¾µÀ£º¡°"+me->name()+"ÊÇÔÚÏßÍæ¼ÒµÚ "
		HIR+chinese_number(no)+NOR" ÎäÑ§¸ßÊÖ£¡¡±\n" NOR, this_object(), me);
	return 1;
}

int ask_dx()
{
	object me = this_player();
    object *ob = filter_array(objects(), (: userp($1) && !wiz_level($1) :));
	int no;

	ob = filter_array(ob,
		(: $2->query("daoxing")	< $1->query("daoxing") :), me);
	no = sizeof(ob) + 1;

	command("say "+me->name()+RANK_D->query_respect(me)+"µÄµÀĞĞÔÚÄ¿Ç°ÔÚÏßÍæ¼ÒÖĞÅÅÃûµÚ "
		HIR+chinese_number(no)+""NOR);
	message_vision( "$NÖ¸×Å$nÔŞÌ¾µÀ£º¡°"+me->name()+"ÊÇÔÚÏßÍæ¼ÒµÚ "
		HIR+chinese_number(no)+NOR" µÀĞĞ¸ßÊÖ£¡¡±\n" NOR, this_object(), me);
	return 1;
}

void create()
{
        set_name(HIM "Ğ¡ÉñÏÉ" NOR, ({ "xiao shenxian","xiao"}) );
        set("gender", "Å®ĞÔ");
        set("age", 20);
        set("title",HIG"ÏÉ×Ó"NOR);
        set("nickname",HIY"¹ûÏÉ"NOR);

        set("per", 40);
	set("long", @LONG

[1;31mÓûÖª»ö¸£ÊÂ£¬ÇëÎÊĞ¡ÉñÏÉ --------[0m

LONG);
        set("combat_exp", 6000000);
        set("daoxing", 6000000);

        set("attitude", "heroism");
        set("str", 193);
        set("per", 40);
        set("max_kee", 650);
        set("max_gin", 700);
        set("force", 2750);
        set("max_force", 2750);
        set("force_factor", 150);
        set("max_mana",2750);
        set("mana",2750);
        set("mana_factor", 150);

       set_skill("literate", 350);
       set_skill("unarmed", 350);
       set_skill("dodge", 350);
       set_skill("force", 350);
       set_skill("parry", 350);
       set_skill("sword", 350);
       set_skill("spells", 350);
	set_skill("moonshentong", 350);
	set_skill("baihua-zhang", 350);
	set_skill("moonforce", 350);
	set_skill("snowsword", 350);
	set_skill("moondance", 350);
	map_skill("spells", "moonshentong");
	map_skill("unarmed", "baihua-zhang");
	map_skill("force", "moonforce");
	map_skill("sword", "snowsword");
	map_skill("parry", "snowsword");
	map_skill("dodge", "moondance");
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
        (: perform_action,"sword", "puosui" :),
        (: cast_spell, "arrow" :),
        (: cast_spell, "mihun" :),
        (: cast_spell, "huimeng" :),
        (: cast_spell, "shiyue" :),
        (: cast_spell, "hufa" :),
        }) );

        set("inquiry", ([
	    "ÇéÒåÒøµ¤" : (: rsg :),
	    "yindan" : (: rsg :),
		"age": (: ask_age :),
		"beauty": (: ask_beauty :),
		"exp": (: ask_exp :),
		"dx": (: ask_dx :),

          ]) );
        set("chat_chance", 10);
        set("chat_msg", ({
            MAG"Ğ¡ÉñÏÉ»÷½Ú¶ø¸è:ÓûÖª»ö¸£ÊÂ£¬ÇëÎÊĞ¡ÉñÏÉ¡£\n"NOR,
            HIY"Ğ¡ÉñÏÉÎûÎûµØĞ¦ÁËĞ¦:ÎÒÒ²Òª³åÉÏ¹âÃ÷±¦Ëş£¡Ê²Ã´Ê±ºò´øÎÒÈ¥ÄØ£¿£¡\n"NOR,
            HIR"Ğ¡ÉñÏÉÉÏÏÂ´òÁ¿×ÅÄã£¬ÑÛÖĞÂ¶³öËÆË®ÈáÇé¡£\n"NOR,           
                (: random_move :)
        }) );

        setup();
   add_money("gold", 5);
        carry_object("/d/moon/obj/feijian")->wield();
        carry_object("/d/obj/cloth/shoupipifeng")->wear();
        carry_object("/d/obj/armor/jinjia")->wear();
        carry_object("/d/qujing/tianzhu/obj/tiekui")->wear();
        carry_object("/d/qujing/baoxiang/obj/zhanpao")->wear();
        carry_object("/d/qujing/qilin/obj/shield")->wear();
        carry_object("/d/obj/cloth/yuanxiang")->wear();
//        carry_object("/d/obj/book/baguatu");
        carry_object("/d/obj/fabao/bagua");

}

string rsg(object me)
{
        me = this_player();

        if( !me->query_temp("rsg/paid") )
        {
                if( me->query_temp("rsg/asked") ) 
                {
                        message_vision("Ğ¡ÉñÏÉ°×ÁË$NÒ»ÑÛ£¬²»Àí$NÁË¡£\n", me);
                        return "½ñÌìÕæÃ»ÒâË¼£¬»¹Ã»¿ªÕÅÄØ£®£®£®\n";
                }
                else
                {
                        me->set_temp("rsg/asked", 1);
                        message_vision(HIR"Ğ¡ÉñÏÉÎûÎûÒ»Ğ¦......\n"NOR, me);
//	    message_vision(HIM"Ğ¡ÉñÏÉ"+HIR"¶¢×Å$N£¬²öµÃÖ±Á÷¹şÀ®×Ó£º²öÒ®£¡£¡£¡\n"NOR, me);

                        return "²»¹ı£®£®£®ÄãÈ·ÊµÒªËãµÄ»°µÃ¸øÎÒ "HIY"30gold \n"NOR;
                }
        }
        else
        {
                me->delete_temp("rsg");
                message_vision("Ğ¡ÉñÏÉÆşÆğÊÖÖ¸Í·£¬¿ªÊ¼¸ø$NËãÆğÀ´......\n", me);
                if(me->query("age")<16)
		    return RANK_D->query_respect(me)+
			"Ğ¡º¢×ÓÒ»±ßÍæÈ¥£¬²»¸øËã£¡\n";
		else
                   return RANK_D->query_respect(me)+"ºÃÀ÷º¦Ò®£¬¾¹È»³ÔÁË "HIR+
		       me->query("rsg_eaten")+NOR" ¸ö"+HIW"ÇéÒåÒøµ¤"+NOR"ÁË£¡£¡£¡\n";

        }
}

int accept_object(object me, object ob)
{
        if( ob->value() >= 300000 )
        {
                message_vision("Ğ¡ÉñÏÉÎûÎûÒ»Ğ¦µØ¶Ô$NµÀ£º"+RANK_D->query_respect(me)+"ÓĞÊ²Ã´ÊÂÄú¾¡¹ÜÎÊ°É£¡\n", me);
                me->set_temp("rsg/paid", 1);
                return 1;
        }
        else
        {
            command("say ÄúÌ«¿ÍÆøÁË,²»¹ı¸øµÄÒ²Ì«ÉÙÁË£¬ÎÒ»¹Òª¿¿×ÅÕâ¸öºı¿ÚÄØ£¡£¡£¡");
            return 1;
        }
}

