//Cracked by Roath
inherit ITEM;
#include <ansi.h>

int do_locate(string arg);
int do_task();

void create()
{
        set_name(HIW"̽��"HIG"ͼ"NOR, ({"tanbao tu","tu"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����һ������Ѱ�Ҷ�ʧ�����̽��ͼ�������зǷ���ħ����\n"+
                            "����(locate)�����ҵ���Ʒ�Ĵ��λ�ã�\n");
                set("unit", "��");
                set("value", 150);
        }
}

void init()
{
   object ob = this_player();
   add_action("do_locate","locate");
  add_action("do_task","task");
}

int do_task()
{
   string output;
if (this_player()->is_busy()) return notify_fail("�𼱣��𼱣�\n");
   output=HIR"̽��ͼ��ͻȻӳ�ֳ�һƪӬͷС�֣�\n\n"NOR;
        output += "������������������������������������������������������\n";
        output += TASK_D->dyn_quest_list();
        output += "������������������������������������������������������\n\n";
        output += YEL"  ��"HIW"��ʾδ���ʹ��     "HIR"��"WHT"��ʾ�Ѿ���ɵ�ʹ��\n"NOR;
   this_player()->start_more(output);
   return 1;
}


int do_locate(string arg)
{
if (this_player()->is_busy()) return notify_fail("�𼱣��𼱣�\n");
   if ( ! arg)

   return notify_fail("locate <��Ʒ>\n");
   else
   if (this_player()->query("sen") < 15)
   return notify_fail("��ķ��������ˡ�\n");
   else
   "/adm/daemons/questd"->locate_quest(this_player(),arg);
   this_player()->add("sen",-5);
   this_player()->start_busy(1);
   return 1;
}

