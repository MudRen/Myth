#include <ansi.h>
#include <dbase.h>
#include <armor.h> 
inherit F_AUTOLOAD;

inherit FINGER;

void create()
{
  set_name(HIB "��ԭ�ι�" NOR, ({ "caoyuan yueguang"}));
  set("weight", 100); 
    set("long",HIR"�»��ָ,�����͸������崿��ͫͫ�Ľ���ָ���������޵�һƬ���İ�Сӱ�����䣡
\n"NOR);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��"); 
    set("no_drop", "�Ϲ������͵İ���������������������\n");  
    set("no_steal", "�Ϲ������͵İ����𶪺��𣿡�\n"); 
    set("no_put", "�Ϲ��͵İ����Ժ�û���ѵ�������Ҳû�����𣿡�\n"); 
    set("no_get", "�Ϲ��͵İ�����get���𣿡�\n");
    set("value", 1000000000);
    set("material", "gold");
    set("armor_prop/armor", 1);
  }
  setup();
}

int query_autoload() { return 1; }
