// wujiang.c �佫

inherit NPC;

void create()
{
        set_name("Ѳ�߹ٱ�", ({ "xunluo guanbing","guanbing", "bing" }));
        set("gender", "����");
        set("age", random(10) + 20);
        set("str", 25);
	set("con", 25);
	set("spi", 25);
	set("dex", 25);
	set("int", 25);
        set("long", "���������ݣ�ɱ�����ڣ���������̼Ұ�ȫ��\n");
        set("combat_exp", 50000);
	set("class", "fighter");
        set("attitude", "herosim");
        set_skill("unarmed", 70);
        set_skill("force", 70);
        set_skill("spear", 70);
        set_skill("dodge", 70);
        set_skill("parry", 70);
	set_skill("bawang-qiang", 30);
	map_skill("spear", "bawang-qiang");
	map_skill("parry", "bawang-qiang");
	set("max_kee", 700);
	set("max_sen", 700);
        set("force", 400); 
        set("max_force", 400);
        set("force_factor", 20);
	set("max_mana", 100);
	set("mana", 100);
	set("mana_factor", 5);
        setup();
        carry_object("/d/obj/weapon/spear/tieqiang")->wield();
        carry_object("/d/obj/armor/tiejia")->wear();
}

int accept_fight(object me)
{
        message_vision("Ѳ�߹ٱ���$N����һ�ɣ��ȵ���߾���󵨣��������£�\n\n", me);
        return 0;
}

int heal_up()
{

        if( environment() && !is_fighting() ) {
                call_out("leave", 1);
                return 1;
        }
        return ::heal_up() + 1;
}

void leave()
{
        object stone;

        this_object()->add("time", 1);
        if( (int)this_object()->query("time") >= 3 ) {
        message("vision",name() + "���˿���ĭ��������´α������������
Ѳ�߹ٱ����˳�ȥ��\n", environment(),this_object() );
        destruct(this_object());

        }
        return;
}

