/***************************************
MUDLIB��Biographies         ����մ���  
Created Admin By Waiwai@2001/02/18
Admin Email��wkzstory@21cn.com         
****************************************/
// Update by waiwai@2001/04/17

inherit NPC;
string try_me(object me);

void create()
{
        set_name("�ذ�", ({"qin an", "qin"}));
        set("title", "�������ܹ�");
        set("gender", "����");
        set("age", 45);

        set("combat_exp", 35000);
        set_skill("unarmed", 70);
	set("force", 200);
	set("force_factor", 10);
        set_skill("dodge", 70);
	set_skill("parry", 70);
        setup();
/*
        set("inquiry", ([
"ٺ��": (: try_me :),
]) );
*/
        carry_object("/d/gao/obj/magua")->wear();
        add_money("silver", 10);

}
void init()
{
        add_action("do_answer", "answer");
}

int do_answer(string arg)
{	
        if( !arg ) return notify_fail("��˵ʲô��\n");
        this_player()->set_temp("pending/jiangjun_answer", 0);
        message_vision("$N�����" + arg + "\n", this_player());
        if( strsrch(arg, "��ʦ") >=0  ) {
                command("haha");
                command("say �����Ҵ����Ҽҽ����书û���ܱȣ�\n");
                this_player()->set_temp("pending/jiangjun_answer", 1);
        } else {
                command("say ���˵ʲôѽ��һ����ȥ��\n");
        }
        return 1;
}

string try_me()
{ 	object me;
	me = this_player();
        if((string)me->query("family/family_name")!="������"){
        return ("��ǹټң�����ٺ��������\n");
	}
	else
        if(!(int)me->query("money_get")){
                me->set("money_get", 1);
        }
        if((int)me->query("money_get") < (int)me->query("combat_exp")){
                add_money("gold", 1);
                command("give 1 gold to " + me->query("id"));
                me->add("money_get", 500);
		return ("��ʱ���ˣ����Ǳ���ٺ����\n");
        }
	else
                me->add("money_get", 100);
		return ("��Ǯ���͹�����ô����Ҫ�ˣ�\n");
}

