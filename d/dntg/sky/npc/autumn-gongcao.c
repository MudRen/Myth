// ��ֵ����
//created 4-8-97 pickle
inherit NPC;
 
void create()
{
        set_name("��ֵ����", ({ "rizhi gongcao", "ri", "day",
"gongcao" }) );
        set("gender", "����" );
        set("long","
��ֵ��������������������ǰ�ͽ������鲻���
��սʧ��������ΪѲ�߹١�������־ͬ���϶���Ϊ
�����ֵܡ���ֵ���������������칬ǰ�ڵظ��䵱
����ʹ�ߣ���������ս����Զ���ϴ���϶�֮�ϡ�\n"
        );
        set("age",35);
        set("str",28);
        set("int",28);
        set("max_kee",1100);
        set("kee",1100);
        set("max_sen",800);
        set("sen",800);
        set("combat_exp",650000);
        set("daoxing",650000);
        set("force",1200);
        set("max_force",1000);
        set("mana",1500);
        set("max_mana",1000);
        set("force_factor", 60);
        set("mana_factor", 60);

        set("eff_dx", 250000);
        set("nkgain", 350);
	
	set_skill("spells", 100);
        set_skill("unarmed",120);
        set_skill("parry",120);
        set_skill("dodge",110);
        set_skill("stick",110);
        set_skill("kusang-bang",110);
	set_skill("moshenbu", 110);
        set_skill("force",120);
        set_skill("jinghun-zhang",100);
	map_skill("dodge", "moshenbu");
	map_skill("unarmed", "jinghun-zhang");
        map_skill("parry","kusang-bang");
	map_skill("stick", "kusang-bang");
        set("inquiry", ([
                "name" : "���¾�����ֵ���ܣ�������������ǰ�󽫡�",
                "here" : "��������칬���¹ٷ���������ڴ�Ѳ�顣",
        ]) );
        setup();
        carry_object("/d/obj/weapon/stick/wuchangbang")->wield();
        carry_object("/d/obj/armor/yinjia")->wear();
}
�
