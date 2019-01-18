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
	return me->name()+RANK_D->query_respect(me)+"����ò��Ŀǰ��������������� "
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
	return me->name()+RANK_D->query_respect(me)+"��������Ŀǰ��������������� "
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

	command("say "+me->name()+RANK_D->query_respect(me)+"����ѧ��Ŀǰ��������������� "
		HIR+chinese_number(no)+""NOR);
	message_vision( "$Nָ��$n��̾������"+me->name()+"��������ҵ� "
		HIR+chinese_number(no)+NOR" ��ѧ���֣���\n" NOR, this_object(), me);
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

	command("say "+me->name()+RANK_D->query_respect(me)+"�ĵ�����Ŀǰ��������������� "
		HIR+chinese_number(no)+""NOR);
	message_vision( "$Nָ��$n��̾������"+me->name()+"��������ҵ� "
		HIR+chinese_number(no)+NOR" ���и��֣���\n" NOR, this_object(), me);
	return 1;
}

void create()
{
        set_name(HIM "С����" NOR, ({ "xiao shenxian","xiao"}) );
        set("gender", "Ů��");
        set("age", 20);
        set("title",HIG"����"NOR);
        set("nickname",HIY"����"NOR);

        set("per", 40);
	set("long", @LONG

[1;31m��֪�����£�����С���� --------[0m

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
	    "��������" : (: rsg :),
	    "yindan" : (: rsg :),
		"age": (: ask_age :),
		"beauty": (: ask_beauty :),
		"exp": (: ask_exp :),
		"dx": (: ask_dx :),

          ]) );
        set("chat_chance", 10);
        set("chat_msg", ({
            MAG"С���ɻ��ڶ���:��֪�����£�����С���ɡ�\n"NOR,
            HIY"С����������Ц��Ц:��ҲҪ���Ϲ���������ʲôʱ�����ȥ�أ���\n"NOR,
            HIR"С�������´������㣬����¶����ˮ���顣\n"NOR,           
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
                        message_vision("С���ɰ���$Nһ�ۣ�����$N�ˡ�\n", me);
                        return "������û��˼����û�����أ�����\n";
                }
                else
                {
                        me->set_temp("rsg/asked", 1);
                        message_vision(HIR"С��������һЦ......\n"NOR, me);
//	    message_vision(HIM"С����"+HIR"����$N������ֱ�������ӣ���Ү������\n"NOR, me);

                        return "������������ȷʵҪ��Ļ��ø��� "HIY"30gold \n"NOR;
                }
        }
        else
        {
                me->delete_temp("rsg");
                message_vision("С����������ָͷ����ʼ��$N������......\n", me);
                if(me->query("age")<16)
		    return RANK_D->query_respect(me)+
			"С����һ����ȥ�������㣡\n";
		else
                   return RANK_D->query_respect(me)+"������Ү����Ȼ���� "HIR+
		       me->query("rsg_eaten")+NOR" ��"+HIW"��������"+NOR"�ˣ�����\n";

        }
}

int accept_object(object me, object ob)
{
        if( ob->value() >= 300000 )
        {
                message_vision("С��������һЦ�ض�$N����"+RANK_D->query_respect(me)+"��ʲô���������ʰɣ�\n", me);
                me->set_temp("rsg/paid", 1);
                return 1;
        }
        else
        {
            command("say ��̫������,��������Ҳ̫���ˣ��һ�Ҫ������������أ�����");
            return 1;
        }
}

