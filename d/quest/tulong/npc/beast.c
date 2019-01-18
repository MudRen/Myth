inherit NPC;

void create()
{
  set_name("������", ({"beast"}));
  set("gender", "����");
  set("age", 10);
  set("long","���˵������˼���γɵĹ����ޣ����ס�˵Ļ��ǡ�\n");
  set("attitude", "aggressive");
  set("combat_exp", 51100000);
  set("max_kee",9000);
  set("kee",9000);
  set("max_sen",9000);
  set("sen",9000);
  set("max_force",9000);
  set("force",18000);
  set("force_factor",200); 
  set_temp("apply/damage", 250);
  set_temp("apply/armor", 200);
  setup();
}

void die ()
{
  object me = this_object();
  object where = environment (me);

  message_vision ("\n$N������ȥ����Ϊһ�����̡�\n",me);  
  if (! present("beast 4",where) &&
      where->query("short")=="����")
  {
    object ob = new ("/d/quest/tulong/npc/beast");
    ob->move(where);
    message_vision ("\nͻȻ���������ֳ���һֻ�����ޣ�\n",me);   
  }
  destruct (me);  
}

void unconcious ()
{
  die();
}


