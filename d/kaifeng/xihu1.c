//Cracked by Roath
// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "����·");
  set ("long", @LONG

һ��С·���ź����������ƣ����ߵĺ�ˮ����һ�㣬�紵����ˮ����
����΢�����ں�ˮ�ϻζ��ų����ĵ�Ӱ����ʱ��ݺ����������������
�����Ŀ�������

LONG);

  set("exits", ([
        "east" : __DIR__"xihu2",
        "southwest" : __DIR__"xihu3",
      ]));

  set("outdoors", __DIR__);

  setup();
}


/*
void init()
{
    add_action("do_dive", "dive");
}
int do_dive()
{   object me,ridee;
        me=this_player();
     ridee=me->ride();
            if( (!present("bishui zhou", me)) &&
            (!((string)me->query("family/family_name")=="��������")) )
                return
notify_fail("��һ����������ˮ�����\n\n��û�����ͱ���ð�����ֻ�øϽ����ϰ�����\n");

   if (ridee && ridee->query("under_water")) {
     message_vision("$Nһ��$n��ͷ�����˴���Ծ��ˮ�С�\n",me,ridee);
     ridee->move("/d/quest/m_weapon/tan/tan1");
   }
    else
                message_vision("$Nһ����������ˮ�У�Ȼ�󲻼��ˣ�\n", me);
                me->move("/d/quest/m_weapon/tan/tan1");
                message_vision("$N���˹�����\n", me);
                return 1;
}

*/
