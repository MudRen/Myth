// jiasha.c
//

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIY"�ǵ�ս��"NOR, ({"zhan pao", "cloth", "pao" }) );
        set("long", HIY"����С��Ϊ�����ɷ����ַ��Ƶ�ս�ۣ����澫�ĵĴ�����һֻ���ܵ�Ұ�ǡ�\n"NOR);
	set_weight(0);
              if( clonep() ) 
                      set_default_object(__FILE__); 
        else {
		set("unit", "��");
		set("material", "cloth");
		set("armor_prop/armor", 40);
		set("armor_prop/dodge", 50);
                set("armor_prop/personality", 10);
                set("value", 50000);

	}
	setup();
}
      int init () 
      { 
        add_action ("do_wear", "wear"); 
        add_action ("do_remove", "remove"); 
        return 1; 
      } 

      int do_wear (string arg) 
      { 
        object me = this_player(); 
        object cloth = this_object(); 
        string name = cloth->query("name"); 
        string msg; 

        if (arg != "pao" &&  arg != "cloth" ) 
          return 0; 
        msg = "$N����һ��"+name+"�����������ڼ��еȴ�����ȥ�����ӡ�\n";  
        cloth->set("wear_msg",msg); 
        return 0; 
      } 

      int do_remove (string arg) 
      { 
        object me = this_player(); 
        object cloth = this_object(); 
        string name = cloth->query("name"); 
        string msg; 

        if (arg != "cloth" && arg != "pao") 
          return 0; 

        msg = "$N��"+name+"���£�Ϭ����������¶��һ˿���顣\n";  
        cloth->set("unequip_msg",msg); 
        return 0; 
      } 

int query_autoload() { return 1; } 
