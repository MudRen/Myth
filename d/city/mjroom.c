//Cracked by Roath
#include <room.h>
#include <ansi.h>
#include <mudlib.h>
inherit ROOM;
void create()
{
set("short",HIR"["+HIY+"�齫��"+HIR+"]"NOR);
set("long", @LONG
����һ��ר�����������Ϣ�����ֳ�����������Ϊ��Ľ�ɫ
�����  ʱ����������Ϣ��Ϊ���߸���Զ��·�����������һͬ
�������Ȧ�ɣ������ɱ�����ڶĲ���ม���������ϸ�Ĺ�����
�����������������䣩
LONG
);
set("light",1);
set("no_fight", 1);
set("no_magic", 1);
      set("freeze",1);
set("no_spells", 1);
set("exits",([
        "down": "/d/city/clubpoem",
]));
set("objects",([
  __DIR__"mjlady3":1,
]));
set("item_desc",([
"board":"
 һ������Ĳ�������  ÿ���ƶ�������롡����һ�򣭣�1w ��������7s
 �����ƾ�   ��"HIY"addin"NOR"        ��ʼ�ƾ�   ��"HIY"start"NOR" 
 ����       ��"HIY"mo"NOR"           �ؿ��ƾ�   ��"HIY"restart"NOR" 
 �����1���ƣ�"HIY".1"NOR"           �����2���ƣ�"HIY".2"NOR" 
 �����3���ƣ�"HIY".3 "NOR"          �����4���ƣ�"HIY".4"NOR" 
 ���Լ����� ��"HIY"."NOR"
 ����       ��"HIY"dump xx"NOR"      ��         ��"HIY"eat xx xx "NOR"        
 ��         ��"HIY"pon"NOR"          ��         ��"HIY"gon "NOR"              
 ��         ��"HIY"hu"NOR"           ��         ��"HIY"tin xx  "NOR"          
 xxΪ���� ����"HIY"eat 2w 3w"NOR" 
",
]));
setup();
}
