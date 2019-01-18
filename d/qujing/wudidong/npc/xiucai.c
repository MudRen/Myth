// xiucai.c 

inherit NPC;
 
void create()
{
        set_name("�ż���", ({ "xiucai", "zhang jidi", "zhang" }));
        set("long", "������Ǵ���Ψһ�����ġ�Ϊ��״Ԫ���ڸ���������ͷ�����Ǹ�����š�\n");
        set("title", "���");
        set("gender", "����");
        set("age", 65);
 
        set_skill("literate", 40);
 
        set_skill("unarmed", 20);
        set_skill("dodge", 20);
        set_skill("parry", 20);
 
        set("combat_exp", 4000);
        set("shen_type", 1);
        setup();
 
        set("chat_chance", 6);
        set("chat_msg", ({
                "�����˵�����Ϸ�дʫ������Ĳã�����һ�񡣾Ϳ�ϧû���ܶ�����������\n",
                "�����˵������֪���������࣬��������ƭǮ�ˡ�\n",
                "�����˵����֮����Ҳ��֮����Ҳ������֪�����ἴ��Ҳ�� \n",
                "�����˵�����Ϸ��ػ������֮�ߣ�����Ҳ�����ҵ������ŵ���ʦүѽ��\n",
        }) );
}
 
int recognize_apprentice(object ob)
{
        if (!(int)ob->query_temp("mark/��"))
                return 0; 
        ob->add_temp("mark/��", -1);
        return 1;
}
 
int accept_object(object who, object ob)
{
        if (!(int)who->query_temp("mark/��"))
                who->set_temp("mark/��", 0);
        if (ob->query("money_id") && ob->value() >= 200) {
                message_vision( "����Ÿ��˵Ķ�$N�����������Ҷ����ˡ�������������Ǯ��û�ˡ�\n", who);
                who->add_temp("mark/��", ob->value() / 50);
                return 1;
        }
        return 0;
}
