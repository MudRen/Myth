// tian-jiang.c
#include <ansi.h>
inherit NPC;
string *first_name = ({ "������","��С��","������","�����","��ѩ��","����з","��δ��","������"});

varargs void drool(string msg, string who);

void create()
{
        string name, id;

        name = first_name[random(sizeof(first_name))];

        set_name(name, ({ "long shi", "long", "shi" }) );
        set("gender", "����" );
        set("long", 
                "���ǴӺ��׸����ﾫѡ��������ʿ\n"
                "��ϸ��է�ۣ�˫�籧£��һ����֪���ո�ǿ��\n"
        );
	set("title", "��ʿ");
        set("age", 25+random(10));
        set("str", 35);
        set("int", 25);
        set("per", 14);
        set("combat_exp",600000);
        set("force",500);
        set("max_force",500);
        set_skill("unarmed",100);
        set_skill("dodge",100);
        set_skill("parry",100);
        set_skill("spear",100);

        setup();
        carry_object("/d/obj/armor/yinjia")->wear();
        carry_object("/d/obj/weapon/spear/tieqiang")->wield();
}

