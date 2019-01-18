//Last modified by waiwai@2002/12/05

#include <armor.h>

inherit OTHERS;

void create()
{
	set_name(HIG "��֮���" NOR, ({ "magic jade", "jade" }) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", HIG "һ�Ż���������Ĺ�ʵ���䣬"
                    "�����Բ�ͬѰ���ĸо���\n" NOR);
                set("value", 200000);
		set("unit", "��");
                set("can_be_enchased", 1);
                set("magic/type", "cold");
                set("magic/power", 150);
		};
}

void init()
{
 	if( this_player()==environment() ) {
	add_action("do_enchase", "enchase");
	add_action("do_enchase", "insert");
	}
}

int do_enchase(string arg)
{
   object in_obj;
   string item;
   string mats;
   int rd,inset_num ;
   object me = this_player();
   object ob = this_object();
   string *colors = ({ HIW, HIR, HIY, HIC, HIM, HIG, HIB });

   if(!arg) return notify_fail("��Ҫ��ʲô��\n");

   if(sscanf(arg, "%s", item)!=1) return notify_fail("��Ҫ�ѱ�ʯ��Ƕ��ʲô�ϣ�\n");

   if(!objectp(in_obj = present(item, me))) return notify_fail("������û������������\n");

   if( in_obj->query("equipped") )
      return notify_fail("����������������������Ƕ��ʯ��\n");

   if( !wizardp(me) && !environment(me)->query("cold"))
             return notify_fail("�˵������������޷���Ƕ��Ʒ��\n");

   if( in_obj->query("no_zm")||in_obj->query_unique())
      return notify_fail("�����Ʒ������Ƕ��ʯ��\n");

   mats = in_obj->query("material");       //װ��������
   inset_num = in_obj->query("inset_num");  // Ƕ�˼�����
   if(!inset_num) inset_num = 1;
   else inset_num = inset_num + 1;
   if(inset_num > 5) return notify_fail(in_obj->query("name")+WHT"���Ѿ���Ƕ��̫��ı�ʯ�ˣ�\n"NOR);
   
   if(!in_obj->query("weapon_prop/damage")) {   //����
       message_vision(CYN"$N��$n"CYN"��Ƕ��"+in_obj->query("name")+CYN"�� \n"NOR,me,ob);
       tell_room(environment(me),
	HIB"ֻ��"+ob->name()+HIB"����һ���׹�,������"+in_obj->query("name")+HIB"����,�����ˣ� \n"NOR);
       in_obj->add("armor_prop/armor",5+random(2));
       in_obj->add("armor_prop/dodge",5+random(2));
       in_obj->set("armor/max_armor",in_obj->query("armor_prop/armor"));

       message_vision(CYN""+in_obj->query("name")+CYN"�ƺ���ø�����ӯ�ˣ�\n"NOR,me);
       in_obj->set_weight(in_obj->query_weight()+500);      
       in_obj->set("inset_num",inset_num);
       in_obj->set("Fmaterial","gem");
       in_obj->add("inset_b",inset_num);
	// ��5���㲻����
       if( (int)in_obj->query("inset_num")>=5) {
       in_obj->set("no_break",1);
       in_obj->set("name",colors[random(sizeof(colors))]+in_obj->query("name")+HIR"("HIY"Ƕ-"+in_obj->query("inset_num")+HIR")"NOR);
	} else
       in_obj->set("name",colors[random(sizeof(colors))]+in_obj->query("name")+NOR);

       if(!in_obj->query("old_long")) in_obj->set("old_long",in_obj->query("long"));
       in_obj->set("long",in_obj->query("old_long")+"������Ƕ��"HIW+(inset_num)+"�ű�ʯ\n"NOR);
       in_obj->save();
       destruct(ob);
       return 1;
	}else{
	//����
       message_vision(CYN"$N��$n"CYN"��Ƕ��"+in_obj->query("name")+CYN"�� \n"NOR,me,ob);
       tell_room(environment(me),
	HIB"ֻ��"+ob->name()+HIB"����һ���׹�,������"+in_obj->query("name")+HIB"����,�����ˣ� \n"NOR);
       message_vision(CYN""+in_obj->query("name")+CYN"�ƺ���ø������������ˣ�\n"NOR,me);
       in_obj->add("weapon_prop/damage",1 + random(10)); //���������˺���
       in_obj->set("max_weapon",in_obj->query("weapon_prop/damage"));

       in_obj->set_weight(in_obj->query_weight()+500);
       in_obj->set("inset_num",inset_num);
       in_obj->set("Fmaterial","gem");
       in_obj->add("inset_b",inset_num);
	// ��5���㲻����
       if( (int)in_obj->query("inset_num")>=5) {
       in_obj->set("no_break",1);
       in_obj->set("name",colors[random(sizeof(colors))]+in_obj->query("name")+HIR"("HIY"Ƕ-"+in_obj->query("inset_num")+HIR")"NOR);
	} else
       in_obj->set("name",colors[random(sizeof(colors))]+in_obj->query("name")+NOR);

       if(!in_obj->query("old_long")) in_obj->set("old_long",in_obj->query("long"));
       in_obj->set("long",in_obj->query("old_long")+"������Ƕ��"HIW+(inset_num)+"�ű�ʯ\n"NOR);
       in_obj->save();
       destruct(ob);
       return 1;
	}
	return notify_fail("����Ƕ��ʯʧ�ܣ�\n");
}

