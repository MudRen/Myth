inherit NPC; 
int ask_me();
void create()
{
        set_name("����", ({ "lianer", "lian er"}) );
        set("gender", "Ů��" );
        set("age", 21);
        set("title", "������Ů��");
        set("long",
        "��������һ�ں����������ó������ˣ�����ѷɫ�����Ů�ӡ�\n");
        set("combat_exp", 5000);
        set("attitude", "friendly");
        set("per",30);
        set_skill("unarmed",30);
        set_skill("dodge",80); 
        set("inquiry", ([
            "����֮��" : (: ask_me :),
            "����" : "�����ǳ�����ģ������Ц�ˡ���\n",
        ]) );

        setup();
        carry_object("/d/quest/tulong/obj/feature")->wear();
}

void do_sing(object ob)
{
   switch(random(2)) {
      case 0:
         message_vision("$Nת������$n΢΢һЦ��\n\n",this_object(),ob);
         break;
      case 1:
         message_vision("$N��ͷ��$n����һЦ��\n\n",this_object(),ob);
         break;
   }
   this_object()->set_temp("marks/song", random(2));
   this_object()->set_temp("marks/songa", 0);
   call_out("singing",2, this_object());
}

int singing (object ob)
{
   int  song, songa; 
   object kid;
   remove_call_out("singing");
   song = ob->query_temp("marks/song");
   songa = ob->query_temp("marks/songa");
   switch(song) {
      case 0:
         switch(songa) {
            case 0:
               message_vision("$N����������\n",ob);
               message_vision("        һ����һ�꣬һ��ûһ�գ�һ����һ�һ����һ����\n",ob);
               ob->set_temp("marks/songa", 1);
   call_out("singing",2,ob);
               break;
            case 1:
               message_vision("        һ��һ���һϲһ���С�һ�һ���ԣ�һ��һ���\n",ob);
               ob->set_temp("marks/songa", 2);
   call_out("singing",2,ob);
               break;
            case 2:
               message_vision("        Ѱһ���ʶ����һ�ᣬ��һ�ᣬ��һ����֪����һ�أ���һ�ء�\n\n",ob); 
               kid = present("kid", environment(ob));
               if(objectp(kid)) {
                  kid->delete_temp("marks/sing");
               }               break;
         }
         break;
      case 1: 
         switch(songa) {
            case 0:
   message_vision("$N������壬����������\n",this_object());
   message_vision("  ����·������·���ϱ�·�������̡������̡�ʮ���̡�\n",this_object());
               ob->set_temp("marks/songa", 1);
   call_out("singing",2,ob);
               break;
            case 1:
   message_vision("  ��һ������һ������һ������ʱ����Ҳĺ����Ҳĺ����Ҳĺ��\n",this_object());
               ob->set_temp("marks/songa", 2);
   call_out("singing",2,ob);
               break;
            case 2:
   message_vision("  б�������̣�����������أ�Ĳ�ɽ������ˮ��������������\n",this_object());
               kid = present("kid", environment(ob));
               if(objectp(kid)) {
                  kid->delete_temp("marks/sing");
               } 
               break;
         }
         break;
   }
}

int ask_me()
{ 
       object me = this_player();
       remove_call_out("ask_for_help");

       command("say ��Ҫ������֮����");
       command("shake");
       command("say �����ܵġ������ټ����ˡ�");
       call_out("ask_for_help",20); 

       return 1;
}

int ask_for_help()
{     
      object ob = this_object(); 
      object me = this_player();
      object where, obj;
      where=environment(me); 
      ob->move(where);      command("tell " + me->query("id") + " �����ˣ����������ֳ��֡����������ǣ�");
      command("say ��������Щ������Ҳ���������ó���");
      obj=new("/d/quest/tulong/obj/string");
      obj->move(ob); 
      command("give string to " + me->query("id"));
      command("say �Ҽ���Ķ�����������ȡ�á���һ��Ҫ�Ʒ���֣�");
        ob->set("inquiry", ([
            "���" : "����˵���Ѿ����˾�������˵ġ���\n", 
            "����֮��" : (: ask_me :),
            "����" : "�����ǳ�����ģ������Ц�ˡ���\n",        ]));
      return 1;
}


