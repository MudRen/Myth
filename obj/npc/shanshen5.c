//��[����֮��[ɽ��
//Created by wuyou@sk_sjsj
//2003-8-13
 
#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIY"����ɽ��"NOR, ({"shan shen", "shen"}));
        set("age", 900);
        set("long", "�Ў[��ɽ֮ɽ��\n");
        set("str", 100);
        set("cor", 40);
        set("con", 40);
        set("cps", 40);
        set("spi", 40);
        set("int", 40);
        set_temp("apply/damage", 150);
        set_temp("apply/armor", 800);
        set("max_kee", 8200);
        set("max_sen", 8200);
        set("force", 18000);
        set("max_force", 10000);
        set("force_factor", 600);
        set("mana", 18000);
        set("max_mana", 10000);
        set("mana_factor", 600);
        set_skill("unarmed", 750+random(50));
        set_skill("parry", 750+random(50));
        set_skill("wuyue-spear", 750+random(50));
        set_skill("dodge", 750+random(50));
        set_skill("spear", 750+random(50));
        set_skill("moshenbu", 750);
        map_skill("spear", "wuyue-spear");
        map_skill("parry", "wuyue-spear");
        map_skill("dodge", "moshenbu");
        set("combat_exp", 70000000);
        set_weight(900000);
        setup();
        carry_object("/d/obj/armor/jinjia")->wear();
        carry_object("/d/obj/weapon/spear/huaji2")->wield();            
        setup();
        
}


