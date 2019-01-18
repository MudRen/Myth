#include <ansi.h>

inherit NPC;
string *first_name = ({ "����", "������", "����ʹ��", "����"});
string *name_words = ({ "С��"});

void create()
{
        string name;
        name = first_name[random(sizeof(first_name))];
        name += name_words[random(sizeof(name_words))];


        set_name(name,({"xiao shen"}));
        set("race", "����");
        set("age", 20);
        set("long", "һ���������ߵ�С���ɡ�\n");
        set("str", 60);
        set("cor", 50);
        set("con", 50);
        set("cps", 50);
        set("spi", 50);
        set("int", 50);
        set_temp("apply/damage", 100);
        set_temp("apply/armor", 500);
        set("max_kee", 3000);
        set("max_sen", 3000);
        set("force", 1500);
        set("max_force", 3000);
        set("force_factor", 150);
        set("mana", 1500);
        set("max_mana", 3000);
        set("mana_factor", 100);
        set_skill("unarmed", 80);
        set_skill("dodge", 150);
        set_skill("parry", 150);
        set_skill("suiyu-zhang", 80);
        set_skill("ningxin-step", 150);
        map_skill("unarmed", "suiyu-zhang");
        map_skill("dodge", "ningxin-step");
        set("combat_exp", 300000);
        set("daoxing", 100000);
        set("limbs", ({ "ͷ��", "����", "ǰ֫", "��", "��Ƥ", "��֫"}) );
        set("verbs", ({ "bite", "claw"}) );
        set_weight(500000);

        setup();
}

void copy_status(object me,object ob)
{
        me->set_skill("unarmed", (int)ob->query_skill("unarmed", 1));
        me->set_skill("dodge", (int)ob->query_skill("dodge", 1));
        me->set_skill("parry", (int)ob->query_skill("parry", 1));
        me->set_skill("suiyu-zhang", (int)ob->query_skill("suiyu-zhang",
1) + 20);
        me->set_skill("ningxin-step", (int)ob->query_skill("ningxin-step", 1)
+ 20);

        me->set("combat_exp",ob->query("combat_exp"));
        me->set("daoxing",ob->query("daoxing"));
}

int heal_up()
{
        if( environment() && !is_fighting() ) {
                call_out("leave", 1);
                return 1;
        }
        return ::heal_up() + 1;
}

void leave()
{
        message("vision",
                HIB + name() +"����������һ�ϣ�˵���������������������ڴ˸�𡱡�\n"
NOR,environment(),  this_object() );
        destruct(this_object());
}

void invocation(object who)
{       int i;
        object *enemy;

        object me=this_object();
        copy_status(me,who);
        message("vision", HIB"���г���һ�����ƣ�"+ name() +
"�������������������������Ƶ�������\n\n"NOR,environment(), this_object() );
        enemy = who->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        kill_ob(enemy[i]);
                        if( userp(enemy[i]) )
enemy[i]->fight_ob(this_object());
                        else enemy[i]->kill_ob(this_object());
                }
        }

}
