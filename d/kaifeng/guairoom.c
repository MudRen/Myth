//Cracked by Roath
// this by calvin at 2001.5

inherit ROOM;

void create ()
{
  set ("short", "�޳�");
  set ("long", @LONG

�޳���������ϰ����Լ��˽���,������һЩ�ɵ��Ĺ���
���������������,������ʱҲ������Щ��ȥ,��һ����
�������˻����,ʱ�����Ҳû��ʲô��,һֱ�ܰ���

LONG);

  set("exits", ([
      "south" : "/d/kaifeng/chen2",
      ]));
  set("objects", ([
        "/d/kaifeng/npc/guaiwu" : 6,
     "/d/kaifeng/npc/shouguan.c" : 1
      ]));

  set("outdoors", __DIR__);

  setup();
}

void init()
{
add_action("do_stop", "whisper");
}

int do_stop(string arg)
{
       object who = this_player();
       object me = this_object();
       message_vision("���ﲻ׼��������\n",who);
       return 1;
}
