//Cracked by Roath
//����ɽ���ɡ�dhxy-evil 2000.7.5
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("ԩ��", ({ "yuan hun", "yuanhun" }));
        set("title", "��ɽǰ��");
        set("race","����");
        set("age", 99);
        set("attitude", "aggressive");
        set("str", 40);
        set("int", 25);
        set("con", 40);
        set("cor", 40);
        
        set("max_kee", 2000);
        set("max_sen", 2000);
        set("force", 3000);
        set("max_force", 2000);
        set("force_factor", 60);
        set("mana", 3000);
        set("max_mana", 2000);
        set("mana_factor", 60);
        set("combat_exp", 500000);
        set("daoxing", 700000);

        set_skill("spells",150);
        set_skill("force", 150);
        set_skill("dodge", 150);
        set_skill("parry", 150);
        set_skill("sword", 150);
        set_skill("zixia-shengong", 150);
        set_skill("sevensteps", 150);
        set_skill("shushan-jianfa",150);
        set_skill("taoism",150);
        map_skill("spells", "taoism");
        map_skill("dodge", "sevensteps");
        map_skill("force", "zixia-shengong");
        map_skill("parry", "shushan-jianfa");
        map_skill("sword", "shushan-jianfa");
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: cast_spell, "jianshen" :),
                (: exert_function, "powerup" :),
        }) );
   add_temp("apply/damage", 20);
   add_temp("apply/armor", 20);

        setup();
        carry_object("/d/obj/cloth/jinpao")->wear();
        carry_object("/d/obj/weapon/sword/qingfeng")->wield();

}

void die()
{
        object me = this_player();
        object ob = new("/d/shushan/obj/qxsword");
        ob->move(environment(me));

        if( environment() ) {
        message("sound", CYN"\nԩ��ɢ��...", environment());
        message("sound", "\nһ������Ů��������������...", environment());
        message("sound", "\nŮ����������ʮ���ˣ��������ڿ��԰�Ϣ�ˣ�������ǽ����͸���������", environment());
        message("sound", "\nŮ��˵����ʧ��������...\n"NOR, environment());
        }
        destruct(this_object());
}