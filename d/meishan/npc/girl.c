
inherit NPC;
int baba();
void create()
{
        set_name("���", ({"er niu", "niu"}));
        set("gender", "Ů��" );
        set("age", 9);
        set("combat_exp", 300);
        set("attitude", "peaceful");
        set("per", 18);
        set("max_kee", 200);
        set("max_sen", 200);
        set("force", 200);  
	set("inquiry", ([
	"��": "������������ĸ��\n", 
	"��ĵ���": (:baba:),
	]) );

        setup();
        carry_object("/d/obj/cloth/shoes")->wear();
}
void init()
{       
        object ob=this_player();

        ::init();

                        remove_call_out("greeting");
                        call_out("greeting", 3, ob);
}

int baba()
{
object who=this_player();
message_vision("�ҵ���������˳��\n",this_object(),this_player());
return 1;
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;

        switch( random(3) ) {
                case 0:
		message_vision("$N�޵�������Ҫ���˴󻨻�ծ��\n", this_object());
		command("cry girl");
                break;
		case 1:
		message_vision("$N�޵�������������Ҫծ�ˣ�\n", this_object());
		command("slogan");
		break;
		case 2:
		message_vision("$N�޵�������˵������ʮ�����ӡ�\n", this_object());
		command("cry " + ob->query("id"));
		break;
        }
}

