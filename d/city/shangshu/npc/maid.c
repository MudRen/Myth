//Creat by waiwai@2001/05/12

inherit NPC;

void create()
{
        set_name("Ѿ��", ({ "maid" }) );
        set("long",
		"�������鸮��˾ְ�����Ѿ�ߣ�һ���ļ����ڳ����С������ص�\n"
		"�ӻ�Ҳ�ڲ�ס���������ʡ�\n"
                );

        set("attitude", "peaceful");

        set("gender", "Ů��");
	set("age", 19);
	set("per", 27);

        set("combat_exp", 1000);

        setup();
        carry_object(__DIR__"obj/pink_cloth")->wear();
}


