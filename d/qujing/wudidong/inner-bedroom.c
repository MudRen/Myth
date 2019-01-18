// inner-bedroom.c
// created by mes
// updated 6/97 by pickle

inherit ROOM;

int do_push(string arg);
void reset();

void create ()
{
  set ("short", "����");
  set ("long", @LONG

����������󾫵������ˡ��ƿ�ˮ�������������ֻ������ɴ�֣�˵
�����ľ��»����������²ȵ�ש����һɫ��ѩ���仨������һ��СС
��齣���ɴΪ�ʣ�����Ϊ������Ķ���һ��һ�Ե����ԧ�졣��ױ̨
�ϰ��Ÿ�ʽ��֬ˮ�ۣ�������ӳ������ǽ�Ϲҵ�һ������(picture)��
���溬�����������ࡣǽ��������ʯ��(men)����֪ͨ��δ���
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"bedroom-gate",
]));
  set("item_desc", ([ /* sizeof() == 2 */
		     "picture" : "
ͼ�ϻ����������󾫡�ֻ��������������ֻ���á�ͼ�����Ͻ�д������С�֡�

��һ�����ײ��ϡ�
���ʬ������Ѫ��

",
		     "men": "
һ�ȳ��ص�ʯ�š�\n",
]));

  setup();
}
void init()
{
  add_action("do_push", "push");
  add_action("do_push", "tui");
}
int do_push(string arg)
{
  object me=this_player();
  int myeffstr=me->query_skill("unarmed",1)/10-2+me->query("str");
  int mystr=me->query_str() + me->query("force_factor");
  int myforce=me->query("maximum_force");

  if ( !arg || ((arg !="men") ))
    return notify_fail("��Ҫ��ʲô�� \n");
  if(mystr <50||myeffstr<20)
    return notify_fail("������̫С�ˣ��Ʋ����� \n");
  if (random(myforce)>1000)
    {
      message_vision("$N��ʯ��ʱ�������ͣ��ƺ��������ˡ�\n", me);
      me->add_maximum_force(-myforce/100);
    }
  message_vision("$Nһ��ʯ�ţ�ͻȻ�䣬һ�������$N�Ƶ�����һ�䷿��ȥ�ˡ�\n", me);
  me->move(__DIR__"cave1");
  message_vision("ʯ�ŷ�ת����$N���˹�����\n", me);
  return 1;
}
