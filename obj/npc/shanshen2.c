//��[����֮��[ɽ��
//Created by wuyou@sk_sjsj
//2003-8-13
 
#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIB"����ɽ��"NOR, ({"shan shen", "shen"}));
        set("age", 500);
        set("long", "���[�Aɽ֮ɽ��\n");
        set("str", 100);
        set("cor", 40);
        set("con", 40);
        set("cps", 40);
        set("spi", 40);
        set("int", 40);
        set_temp("apply/damage", 150);
        set_temp("apply/armor", 800);
        set("max_kee", 5200);
        set("max_sen", 5200);
        set("force", 14000);
        set("max_force", 7000);
        set("force_factor", 350);
        set("mana", 14000);
        set("max_mana", 7000);
        set("mana_factor", 350);
        set_skill("unarmed", 450+random(50));
        set_skill("parry", 450+random(50));
        set_skill("wuyue-spear", 450+random(50));
        set_skill("dodge", 450+random(50));
        set_skill("spear", 450+random(50));
        set_skill("moshenbu", 450);
        map_skill("spear", "wuyue-spear");
        map_skill("parry", "wuyue-spear");
        map_skill("dodge", "moshenbu");
        set("combat_exp", 40000000);
        set_weight(900000);
        setup();
        carry_object("/d/obj/armor/jinjia")->wear();
        carry_object("/d/obj/weapon/spear/huaji2")->wield();    
        
}


