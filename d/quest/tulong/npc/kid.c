inherit NPC;
void create()
{
        set_name("�ܵ�", ({ "kid"}) );
        set("gender", "����" );
        set("age", 5);
        set("title", "������С��");
        set("long",
                "���������ӣ�ü��Ŀ�㣬�ɰ�֮����\n");
        set("combat_exp", 50000);
        set("attitude", "friendly");
        set("per",15);
        set_skill("unarmed",50);
        set_skill("dodge",50);

        setup();
}

void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        object  lianer;

        if( !ob || environment(ob) != environment() ) return;
        lianer = present("lian er", environment(ob));
        if(!objectp(lianer)){
        message_vision("$N˵���������㳪�ĸ�������ˣ���\n",this_object(),ob);
           return;
        }
        if(query_temp("marks/sing") == 1) {
           return;
        }
        switch( random(2) ) {
                case 0:
message_vision("$Nҡ���������֣�˵����������㣬����С���������ɡ���\n",this_object(),ob);
                        break;
                case 1:
message_vision("$N����������˵������㣬��Ҫ��С��������\n",this_object(),ob);
                        break;
        }
        this_object()->set_temp("marks/sing", 1);
        lianer->do_sing(ob);
}

int accept_object(object who, object ob)
{
   string       id;
   int          kar, c;
   object obj;

   id = ob->name(); 
   if ((string)ob->query("id") == "fish") {
   message_vision("$N˵�������ۣ��ô���㣡��\n",this_object()); 
   message_vision("$N˵��������л��������������͸��㡣��\n",this_object());
   obj=new("/d/quest/tulong/obj/kite");
   obj->move(this_player());
   return 1;
   }    
   message_vision("$N˵��������л����!��\n",this_object());
   if(id == "�ƽ�" || id == "����"){
     kar = (int)who->query_kar();
     c = (int)ob->value();
     if(random(c) > random(10000*(1000-kar*2))) {
        who->add("weiwang", 1);
     }
   }
   return 1;
}


