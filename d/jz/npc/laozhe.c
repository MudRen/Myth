//Cracked by Roath
inherit NPC;
string ask_book();
void create()
{
        set_name("����", ({"old man","lao zhe","man"}));
        set("gender", "����");
        set("age", 58);
        set("long","һ�����ع�ϡ�����ˣ���˵���Ͱ������д״ֽ�����򱨲�ƽ��");
        set("attitude", "friendly");
        set("per", 30);
        set("str", 30);
        set("combat_exp",2000);
	set("daoxing",2000);	
        set("max_kee",300);
        set("max_sen",300);
        set("inquiry", ([
                "��״" : (: ask_book :),
                "״ֽ" : (: ask_book :),
                        ]) );
        setup();
}
string ask_book()
{
        object ob;
        object me = this_player();
        ob = new("/d/jz/obj/paper");
        if(me->query("bellicosity")>100) {
        ob->move(this_player());
        return "������������Ѫ���������д�õ�״ֽ����״ȥ�ɡ�";
                                          }
        else
        return "ƽ���޹ʣ���ʲô״����";
}
