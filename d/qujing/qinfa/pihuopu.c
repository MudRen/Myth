// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "Ƥ����");
  set ("long", @LONG

�ſ�ɹ�ż��Ÿ����õ�Ƥ����������ʽ������Ƥ����Ұ��
Ƥ���ݽ����ż��ڴ�Ⱦ�ף����滹Ⱦ��һЩƤ�����������л�
�ܳ����Ŵ��۵�Ƥ��Ʒ��

LONG);

  set("exits", ([
        "east"    : __DIR__"jiedao4",
      ]));
  set("objects", ([
"/obj/boss/qinfa_sun"    : 1,
      ]));
  setup();
}

