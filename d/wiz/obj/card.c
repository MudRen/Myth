#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIR"ʥ����"NOR, ({ "chrismas card","card" }) );
        set("long",
HIY"һ�ž�����ʥ����(card)���������(open)������!\n"NOR);
        set("unit", "��");
        set("weight", 100);
        set("value", 0);
        set("no_sell","��ô�����������ﲻ��Ŷ" );
        set("no_drop","��ô�������� ���˿�ϧŶ" );
        set("no_get","��ô�������� �ò�����Ŷ" );
        set("no_give","��ô�������� ���Լ�����Ŷ" );
  setup();
}

int init ()  
{   
  add_action ("do_open", "open");
  return 1;
}

string rdm(string *strs)
{
  return strs[random(sizeof(strs))];
}

int do_open (string arg)
{
  string *hows = ({
    "����Ҹ���",
    "��������",
    "��������",
    "�����̵�",
    "��Ϊ�����",
    "��ͷ������",
    "�м����ܵ�",
    "������",
    "�����û��������",
    "ׯ�ϵؿ��Ŵ�ң�Ȼ���¸ҵ�",
    "���������",
    "����������",
    "�������ɵ�",
    "�������ۣ�",
    "ҡͷ���Ե�",
    "����һЦ��",
    "����һ��",
    "���ֱ��ŵ�",
    "��ͷ���Ե�",
    "������Ц����������",
    "�ƿ����ˣ��ںü�ʽ��",
    "��ͷ�����",
    "�˷ܵ���ͷ�󺹣�",
    "��Ƽ��ݵ�",
    "Ĩȥ�۽ǵ��Ứ��",
    "����֣�һ��ţ�",
    "������צ��",
    "ʮ��ǫ���",
    "�ߵ�����ͨ�죬",
  });

  string *manners = ({
    "��$n��",
  });


  message_vision ("$N"+rdm(hows)+rdm(manners)+"��\n",
                  this_player(),this_object());

	if (this_object()->query("owner")==this_player()->query("id")) 
{
  message_vision ("$Nֻ������ǰ���һ������æ����ϸ��...\n",
                  this_player(),this_object());
//this_player()->set("yudian/card","got");
this_player()->add("max_force",4);
this_player()->add("max_mana",4);
this_player()->save();
write(HIW"����д��:\n"
HIR"��õ���4�������ͷ���\n"
HIM"ףʥ������!\n"
HIM"                     ����"HIG"��"HIY"��ʦ��\n"NOR,
               environment(this_player()), this_player());
  destruct(this_object());
  return 1;
}

  message_vision ("$n��ĳ�һֻ����ͷ����������$N�Դ���...\n",
                  this_player(),this_object());
return 1;
}
	
