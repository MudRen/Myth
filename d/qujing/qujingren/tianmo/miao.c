inherit ROOM;


void append_laoren();
void dis_laoren();

void create ()
{
  set ("short", "��ħ��");
  set ("long", @LONG
СС�ĵط�ȴ������һ��ܴ������,���Ϸ���������д�š���ħ��.
����ħ��֪���Ǻη���ʥ��С������𲻶ϣ������ˡ������Ӧ����
���������ꡰ.�������Ǻ�����ģ������̲�סҲ��ߵ�ݡ�
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"out",	//����û���趨���ڣ���֪��Ҫ���������
  "north" : __DIR__"zoulang1",
]));

  setup();
}

void init()
{
    add_action("do_bai","koubai");
    add_action("do_bai","knock");

}

int do_bai()
{
    object me,who;
    me=this_object();
    who=this_player();
   
    message_vision("$N�����ϵ�ߵ�����������������дʣ���..��..��..��\n",who);
  
    if (OBSTACLE_D->query("cated_qjr"))
	{
	    	return 1;
  	}

    if (!present("zhenglong laoren",me) ) 
      	{
         	remove_call_out("append_laoren");
         	call_out("append_laoren",5);
 	}
    return 1;	
}


void append_laoren()
{
	object laoren;
	object me=this_object();

	laoren=new("/d/qujing/qujingren/tianmo/npc/laoren");
	laoren->move(me);
     	message_vision("$N�ƿ�Ļ�����˳���\n",laoren);
	
	remove_call_out("dis_laoren");
	call_out("dis_laoren",60);
}

void dis_laoren()
{
	object laoren;
	object me=this_object();

	if (laoren=present("zhenglong laoren",me))
	   {
     		message_vision("$Nת���������\n",laoren);
		destruct(laoren);
	   }	
}

int valid_leave (object who, string dir)
{
  if (dir=="south")return ::valid_leave(who,dir); 
  if (!OBSTACLE_D->query("cated_id"))
	return notify_fail("��㴳����²�̫�ð�\n");
  if (who->query("obstacle/qujing")=="ren")
    {	//��������Ҫ��һ����ʱ��ſ��Խ�ȥ��ץ������ʱ�䲼��
	if (!OBSTACLE_D->query("open_door"))
	  return notify_fail("���ڻ����Ǵ���ȥ��ʱ��\n");
    } 

  return ::valid_leave(who,dir);

}

