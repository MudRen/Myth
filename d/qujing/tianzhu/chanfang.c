// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

��������Ѿ���һ��ʱ�䲻���ˣ�ǽ�����䣬������һ���ң�
ǽ�ǵ��ż����ƾɵ����ţ������ϸ���һ���ز���ɮ�ۡ�����
����������һ�ţ�ͨ���Ժ�Ĳ�԰С����

LONG);

  set("exits", ([
        "northwest"   : __DIR__"houyuan",
      ]));
  set("objects", ([
        __DIR__"npc/realgirl"   : 1,
      ]));

  setup();
}


