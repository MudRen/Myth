//Cracked by Roath
// Room: /moon/ontop.c
//cglaem...12/13/96.

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

�����̲���Ʈ��һҶС�ۣ�һ��������Ů��ִ˫����������ˮ����������
����С�������������ǣ���������������̣���������������ַ��Ī��
ת��������������һЦ�����档��ɽ�������շ��������ʺ����ǹ��ꣿ��
����������а��ȴ��һ˿�����ĵ��˸С���̲��˥�ݲ��⣨��������
�������⡣
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "lotus" : "�ɻ��Ѿ�л�ˣ������Ϲ�����ĵ������
",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/chimeng" : 1,
]));
  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"rain",
]));

  setup();
}

void init()
{
  add_action("do_cai", "cai");
}

int do_cai(string arg)
{
  object me=this_player();
  object m; 

  if( (!arg) || !((arg == "lotus") || (arg == "lian")))
    return notify_fail("��ʲô��\n");
  message_vision("$N�����������ˣ�������ȥժ��\n", me);
 if (me->query("kee") < (int)(me->query("max_kee")/3))
	return notify_fail("����ЪЪ�ɣ�����ô��:)\n");

 else if (random(6) < 1){
	message_vision("$N����һ������ͨһ�������������أ�\n",me);
	me->move(__DIR__"hudi");
	return 1;
	}
  else if (me->query("gender") == "����")
	return notify_fail("��ͻȻ��ʶ������������ʧӢ�۱�ɫ�������ְ������˻���\n");	
  else{
	if ((int)me->query_skill("moondance", 1)< 60){
          me->improve_skill("moondance", 40-me->query("str"));
	   message_vision(
		 "$N����������ѧ���Ṧ�������Ϻ�Ҷ�����ֲ����ָϽ����˻�����\n", me);   
          tell_object(me, "�������һЩ����������ļ��ɡ�\n");
	  this_player()->start_busy(1);
        }
      else
        {
          message_vision("$N˫������Ҷ��һ�㣬����������ˮ���ӹ�������ʱ�����Ѷ���һֻ���\n", me);
	  if(sizeof(all_inventory(this_player()))>30)
	      tell_object(me,"�����������Ѿ�װ�����ˡ�\n");
	  else {
            m = new(__DIR__"obj/lianzi.c");
	    m->move(this_player()); 
	    this_player()->start_busy(1);
	  }
	}
	}
       me->receive_damage("kee", 20);
	return 1;
}
