inherit NPC;
#include <ansi.h>

string ask_mofeng();
#define MOFENGD  "/d/quest/mofeng/mofengd"
void create()
{

        set_name("���ع���", ({ "tu di", "mofeng tudi", "tudi" }) );
        set("gender", "����" );
        set("long", "�����İ׷����Ͱ����׵İ�ü�Ϲ����������ֳ�һ�����ȡ�\n");
        set("age",200);
        set("title", "����ħ�������ص�");
        set("str", 40);
        set("int", 30);
        set("con", 30);
        set("spi", 30);
        set("per", 30);
        set("class", "xian");
        set("attitude", "heroism");
        set("combat_exp", 1500000);
        set("daoxing", 2000000);
        set("max_kee", 20000);
        set("max_sen", 20000);
        set("force",5000);
        set("max_force",3000);
        set("force_factor", 150);
        set("mana", 5000);
        set("max_mana", 3000);
        set("mana_factor", 150);

      
       

        set_skill("unarmed",170);
        set_skill("dodge",400);
        set_skill("parry",170);
        set_skill("sword", 180);
        set_skill("force", 170);
        set_skill("spells", 170);
        set_skill("changquan", 170);
        set_skill("liangyi-sword", 180);
        set_skill("baguazhou", 170);
        set_skill("moshenbu", 170);
        set_skill("lengquan-force", 170);
        map_skill("unarmed", "changquan");
        map_skill("force", "lengquan-force");
        map_skill("spells", "baguazhou");
        map_skill("sword", "liangyi-sword");
        map_skill("parry", "liangyi-sword");
        map_skill("dodge", "moshenbu");

        set("chat_chance",10+random(5));
        set("chat_msg", ({
                    name()+"˵�����������������ɴӴ˶��ֶ���!\n",
                    }));

        seteuid(getuid());

        set("inquiry", ([
        "����ħ����": (: ask_mofeng :),
        "ħ����":     (: ask_mofeng :),
           ]) );

        setup();
        carry_object("/d/obj/cloth/baipao")->wear();
        carry_object("/d/obj/weapon/staff/muzhang")->wield();
}

string ask_mofeng()
{
        object who = this_player();
        
        if (!userp(who)) return "��!\n";
        if (who->query("combat_exp")<1000000) return who->name()+"��ѧ̫�ͻ��Ǳ�ȥΪ��!\n";
        MOFENGD->add_player_list(who);
}
