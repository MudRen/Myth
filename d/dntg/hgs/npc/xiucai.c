inherit NPC;

void create()
{
        set_name("��ͼ��", ({"lan tuyu","lan","xiansheng"}));
        set("gender", "����");
        set("age", 55);
        set("title", "��������");
        set("str", 25);
        set("int", 30);
	set("long", "��ͼ��ԭ�Ǵ���һ����ţ������Բ��У���Ư�����⵽��������\n");
        set("combat_exp", 30000);
        set("attitude", "friendly");
        set_skill("literate", 40);
        set("force", 500); 
        set("max_force", 500);
        set("inquiry", ([
                "����ʶ��": "���ˣ��������Եط��ˣ�\n",
        ]) );
        setup();
        carry_object("/d/obj/cloth/changpao")->wear();
}
int recognize_apprentice(object ob, object who)
{
        return 1;
}


