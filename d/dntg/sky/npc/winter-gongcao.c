// ��ֵ����
//created 4-8-97 pickle
inherit NPC;
 
void create()
{
        set_name("ʱֵ����", ({ "shizhi gongcao", "shi", "hour",
"gongcao" }) );
        set("gender", "����" );
        set("long","
��ֵ��������������������ǰ�ͽ������鲻���
��սʧ��������ΪѲ�߹١�������־ͬ���϶���Ϊ
�����ֵܡ�ʱֵ����������ô������������ء���
���������ֵ�����ߣ�����ȱ�����顣\n"
        );
        set("age",35);
        set("str",25);
        set("int",25);
        set("max_kee",1000);
        set("kee",1000);
        set("max_sen",1000);
        set("sen",1000);
        set("daoxing",490000);
        set("combat_exp",490000);
        set("force",1000);
        set("max_force",800);
        set("mana",1500);
        set("max_mana",900);
        set("force_factor", 50);
        set("mana_factor", 50);

        set("eff_dx", 200000);
        set("nkgain", 300);

        set_skill("unarmed",110);
        set_skill("parry",100);
        set_skill("dodge",100);
        set_skill("spear",100);
        set_skill("bawang-qiang",100);
	set_skill("moshenbu", 100);
        set_skill("force",100);
	set_skill("spells", 100);
        set_skill("dragonfight",90);
	map_skill("unarmed", "dragonfight");
	map_skill("dodge", "moshenbu");
	map_skill("spear", "bawang-qiang");
        map_skill("parry","bawang-qiang");
        set("inquiry", ([
                "name" : "���¾���ʱֵ���ܣ�������������ǰ�󽫡�",
                "here" : "��������칬���¹ٷ���������ڴ�Ѳ�顣",
        ]) );
        setup();
        carry_object("/d/obj/weapon/spear/biyuqiang")->wield();
        carry_object("/d/obj/armor/yinjia")->wear();
}
�
