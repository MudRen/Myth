// ��ֵ����
//created 4-8-97 pickle
inherit NPC;
 
void create()
{
        set_name("��ֵ����", ({ "nianzhi gongcao", "nian", "year",
"gongcao" }) );
        set("gender", "����" );
        set("long","
��ֵ��������������������ǰ�ͽ������鲻���
��սʧ��������ΪѲ�߹١�������־ͬ���϶���Ϊ
�����ֵܡ���ֵ�������Ǵ�磬һ����ҹ����ͬ
С�ɡ�\n"
        );
        set("age",41);
        set("str",28);
        set("int",25);
        set("max_kee",1100);
        set("kee",1100);
        set("max_sen",1000);
        set("sen",1000);
        set("combat_exp",580000);
        set("daoxing",580000);
        set("force",1500);
        set("max_force",1000);
        set("mana",1700);
        set("max_mana",1000);
        set("force_factor", 60);
        set("mana_factor", 50);

        set("eff_dx", 220000);
        set("nkgain", 350);

        set_skill("unarmed",120);
        set_skill("parry",120);
        set_skill("dodge",110);
        set_skill("stick",110);
        set_skill("qianjun-bang",100);
        set_skill("force",120);
	set_skill("puti-zhi", 100);
	set_skill("moshenbu", 110);
	set_skill("spells", 100);
	map_skill("unarmed", "puti-zhi");
	map_skill("dodge", "moshenbu");
	map_skill("stick", "qianjun-bang");
        map_skill("parry","qianjun-bang");
        set("inquiry", ([
                "name" : "���¾�����ֵ���ܣ�������������ǰ�󽫡�",
                "here" : "��������칬���¹ٷ���������ڴ�Ѳ�顣",
        ]) );
        setup();
        carry_object("/d/obj/weapon/stick/wuchangbang")->wield();
        carry_object("/d/obj/armor/yinjia")->wear();
}
�
