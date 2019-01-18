inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG
һ��ټ����������ڷ�������,�Ĵ���������,��������,��ֵ���
��Ȼû��һ˿����.��ֻ�о�����,����һ��Ī������ζ.
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"zoulang7",
]));

  setup();
}

void init()
{
   add_action("do_xian","xian");
   add_action("do_xian","��");
}

int do_xian()
{
  object qujingren,rou;
  object me=this_object();
  object who=this_player();

  
  if (me->query_temp("xian"))return 0;
  if (who->query("obstacle/qujing")=="ren")
    {
  	message_vision("$N�������ƿ�������,����������ȡ��������������\n",who);
  	message_vision("$Nһ�Ѱ�ȡ���˱��˳���\n",who);
 
  	qujingren=new("/d/qujing/qujingren/"+OBSTACLE_D->query("guan")
                   +"/qujingren");
  	qujingren->move(me);
  	me->set_temp("xian",1);
  
  	who->command_function("cry qujing ren");
  	remove_call_out("append_laoren");
  	call_out("append_laoren",5);
	return 1;
    } 
  if (who->query("id")==OBSTACLE_D->query("cated_id"))
    {
	if (OBSTACLE_D->query("obstacle_fail"))
	  {
		message_vision("$N�˸߲��ҵ�����������,����!����ȡ���˵���\n",
			who);
		who->command_function("rumor "+who->query("name")+
			"�������ȡ���˵���");
		for (int i=1;i<=6;i++)
		   {
 		      rou=new("/d/qujing/qujingren/obj/rou");
		      rou->move(who);
		   }	
		OBSTACLE_D->delete("cated_id");
		return 1;
	  }  
    }
    return notify_fail("���������Ŷ�����,��û��Ļ�����ò�Ҫ����\n");


}

void append_laoren()
{
	object laoren;
	object me=this_object();

	laoren=new("/d/qujing/qujingren/tianmo/npc/laoren");
	laoren->move(me);
     	message_vision("$N���˹���\n",laoren);
	
}


