// wujiang.c �佫

inherit NPC;

void create()
{
        set_name("�߹��ؽ�", ({ "wu jiang", "wu", "jiang" }));
        set("gender", "����");
        set("age", random(10) + 35);
        set("str", 30);
        set("long", "���������ݣ�ɱ�����ڣ���Ȼֻ�Ǹ��س��ŵ�С�٣�����Ҳ�Ǵ�����̵ġ�\n");
        set("combat_exp", 200000+random(30000));
        set("attitude", "peaceful");
        set_skill("unarmed", 110);
        set_skill("force", 110);
        set_skill("spear", 110);
        set_skill("dodge", 110);
        set_skill("parry", 110);
	set("max_kee", 800);
	set("max_sen", 800);
        set("force", 600); 
        set("max_force", 600);
        set("force_factor", 30);

        setup();
        carry_object("/d/obj/weapon/spear/tieqiang")->wield();
        carry_object("/d/obj/armor/tiejia")->wear();
}

int accept_fight(object me)
{
        message_vision("�߹��ؽ��������ĩ����������ˡ�����㣡\n\n", me);
        return 0;
}
