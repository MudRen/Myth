// ��ֵ����
//created 4-8-97 pickle
inherit NPC;
 
void create()
{
        set_name("��ֵ����", ({ "yuezhi gongcao", "yue", "month",
"gongcao" }) );
        set("gender", "����" );
        set("long","
��ֵ��������������������ǰ�ͽ������鲻���
��սʧ��������ΪѲ�߹١�������Ϊ־ͬ���Ͻ�Ϊ
�����ֵܡ���ֵ���������϶�������ʦ�¹���һ��
����ѩɽ���������ڰٻ������м������ּ��\n"
        );
        set("age",38);
        set("str",20);
        set("int",30);
        set("max_kee",1050);
        set("kee",1050);
        set("max_sen",900);
        set("sen",900);
        set("combat_exp",550000);
        set("daoxing",550000);
        set("force",1500);
        set("max_force",900);
        set("mana",1450);
        set("max_mana",850);
        set("force_factor", 60);
        set("mana_factor", 50);

        set("eff_dx", 200000);
        set("nkgain", 340);

        set_skill("unarmed",110);
        set_skill("parry",100);
        set_skill("dodge",100);
        set_skill("sword",110);
        set_skill("snowsword",115);
        set_skill("force",100);
	set_skill("moshenbu", 110);
	set_skill("baihua-zhang", 90);
	set_skill("spells", 100);
	map_skill("unarmed", "baihua-zhang");
	map_skill("dodge", "moshenbu");
        map_skill("parry","snowsword");
	map_skill("sword", "snowsword");
        set("inquiry", ([
                "name" : "���¾�����ֵ���ܣ�������������ǰ�󽫡�",
                "here" : "��������칬���¹ٷ���������ڴ�Ѳ�顣",
        ]) );
        setup();
        carry_object("/d/obj/weapon/sword/qingfeng")->wield();
        carry_object("/d/obj/armor/yinjia")->wear();
}
�
