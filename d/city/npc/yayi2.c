//Last modified by waiwai@2001/04/24
// yayi.c  �ٸ�����
inherit NPC;
void create()
{
	set_name("����", ({ "ya yi", "ya" }));
	set("gender", "����");
	set("age", 25);
	set("long", "һ���ߴ����͵ĺ��ӣ���Ϊ���ڹٸ����£������Ѿ�ĥ���ú��ޱ��顣\n");
	set("combat_exp", 500000);
	set("shen_type", 1);
        set_skill("unarmed", 30);
        set_skill("dodge", 30);
	setup();
	carry_object("/d/city/obj/yayifu")->wear();
}
	
