// created 6/5/1997 by snowcat
#include <ansi.h>

#define MAXPOSITION 7

inherit ITEM;

void create()
{
  set_name("����¼", ({ "zishou lu", "zishou",  "lu" }) );   
  set_weight(10);
  setup();
  set("unit", "��");
/*
  set("long", @LONG

               �������ȡ������������ء������������ض���
                  ��              ��              ��
                  ��              ��              ��
��ϼͤ            ��            ��Ǭ��            ��            ���̸�
  ��  ��        ��ǧ��        ��  ��  ��        ��ǧ��        ��  ��
��ϼͤ�����԰�����԰�����԰����������԰�����԰�����԰�����̸�
  ��  ��          ��          ��  ��  ��          ��          ��  ��
��ϼͤ            ��            �����            ��            ���̸�
  ��  ��        ��ǧ��        ��  ��  ��        ��ǧ��        ��  ��
��ϼͤ�����԰�����԰�����԰����徵���԰�����԰�����԰�����̸�
  ��  ��          ��          ��  ��  ��          ��          ��  ��
��ϼͤ            ��            Ϧ����            ��            ���̸�
  ��  ��        ��ǧ��        ��  ��  ��        ��ǧ��        ��  ��
��ϼͤ�����԰�����԰�����԰���������԰�����԰�����԰�����̸�
  ��  ��          ��          ��  ��  ��          ��          ��  ��
��ϼͤ            ��            ��ب��            ��            ���̸�
                  ��              ��              ��
                  ��              ��              ��
                �ʷ�����������������̨����������������
                                  ��


LONG
  );
*/
  set("long", "");

  setup();
}

void reset_long (object me);

void init()
{
  reset_long (this_object());
}


void reset_long (object me)
{
  int i, j;
  string dir;
  string str;

  if (me->query("long_modified"))
    return;

  me->set("long_modified", 1);

  str = @LONG


                  �ԡԡԡԡԡԡԷ����ԡԡԡԡԡԡ�
LONG;

  dir = "/d/pantao/";
  for (i = 1; i <= MAXPOSITION; i++)
  {
    string npc = dir + "npc/tian"+sprintf("%d",i);
    string s;
    object ob = find_object(npc);
    if (! ob ||
        ! ob->restore())
      ob = new (npc);
    if (ob &&
        s = ob->query("short"))
    {
      string honor;
      sscanf(s, "%s(%s", honor, s);
      s = ob->query("current_player");
      if (s != "none of us")
      {
        honor = honor + " " + s;
        for (j = strlen(honor); j < 30; j++)
          honor = honor + " ";
        str = str + "                    " + honor + "   \n";
      }
    }
  }
  str = me->query("long") + str +
"                  �ԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡ�\n\n";
  me->set("long",str);
}


