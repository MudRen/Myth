// self-made fabao

#include <ansi.h>
#include <weapon.h>
#include <armor.h>
#include <login.h>

inherit F_CLEAN_UP;

#define MAX_FABAO	3

string  fabao_type, fabao_id, fabao_name, fabao_desc;
int		fabao_subtype;

void get_type(string arg, object ob);
void get_subtype(string arg, object ob);
void get_id(string arg, object ob);
void get_name(string arg, object ob);
void get_desc(string arg, object ob);
void build_weapon(object ob);
void build_armor(object ob);
int check_legal_name(string name, int max_len);
int check_legal_id(string name);


void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	int  fabao_num;

	if( me->query("combat_exp") < 20000)
		return notify_fail("��ĵ��в������������취����\n");
	
	if( me->query("max_force") < 300 )
		return notify_fail("��������������������취����\n");
		
	if( me->query("max_mana") < 300)
		return notify_fail("��ķ����������������취����\n");
	
	if( me->query("force") < (me->query("max_force")+100) )
		return notify_fail("����������㣬�������취����\n");
	
	if( me->query("mana") < (me->query("max_mana")+100) )
		return notify_fail("���ħ�����㣬�������취����\n");
	
	if( me->query("kee") != me->query("max_kee") ||
	    me->query("sen") != me->query("max_sen") ) 
		return notify_fail("��ľ������㣬�������취����\n");

    fabao_num = 0;		
	if( me->query("fabao/weapon") )		fabao_num++;
	if( me->query("fabao/armor1") )		fabao_num++;
	if( me->query("fabao/armor2") )		fabao_num++;
	
	if( fabao_num >= MAX_FABAO )
		return notify_fail("�㲻�������Ʒ����ˣ����� dispose ����Ҫ�ķ�����\n");
		
	write("��Ҫ�����෨����\n");
	if( !me->query("fabao/weapon") )
		write("w. ����\n");
	if( !me->query("fabao/armor1") || !me->query("fabao/armor2") )
		write("a. ����\n");

	// Other kinds of fabao can be added too.. if there is somefile
	// we can use as a default object.
	write("��ѡ��");
	input_to( (: get_type :), me );
	
	return 1;	
}

void get_type(string arg, object ob)
{
	if( (arg != "w" || ob->query("fabao/weapon"))
	  && (arg != "a" || ( ob->query("fabao/armor1")
	  && ob->query("fabao/armor2") )) )   {
		write("��Ҫ�����෨����\n");
		if( !ob->query("fabao/weapon") )
			write("w. ����\n");
		if( !ob->query("fabao/armor1") || !ob->query("fabao/armor2") )
			write("a. ����\n");
		write("��ѡ��");
		input_to( (: get_type :), ob );
		return;
	}

	if( arg == "w" )    {
		fabao_type = "weapon";
		write("\n");
		write("��ѡ���������ࣺ\n");
		write("1. ��  2. ��  3. ��  4. ��  5. �  6. ǹ\n");
		write("7. ��  8. ��  9. ��  10. ��\n");
		write("��ѡ��");
	}
	else if( arg == "a" )   {
		fabao_type = "armor";	
		write("\n");
		write("��ѡ��������ࣺ\n");
		write("1. ��  2. Ь  3. �·�  4. ָ��  5. ����  6. ͷ��\n");
		write("7. ����  8. ��  9. ����  10. ����  11. ����\n");
		write("��ѡ��");
	}
	input_to( (: get_subtype :), ob);
}

void get_subtype(string arg, object ob)
{
    int  order;
    
    sscanf(arg, "%d", order);
    
	if( (fabao_type == "weapon" && order <= 0 && order > 10) ||
	  (fabao_type == "armor" && order <= 0 && order > 11) )  {
		if( arg == "w" )    {
			fabao_type = "weapon";
			write("\n");
			write("��ѡ���������ࣺ\n");
			write("1. ��  2. ��  3. ��  4. ��  5. �  6. ǹ\n");
			write("7. ��  8. ��  9. ��  10. ��\n");
			write("��ѡ��");
		}
		else if( arg == "a" )   {
			fabao_type = "armor";	
			write("\n");
			write("��ѡ��������ࣺ\n");
			write("1. ��  2. Ь  3. �·�  4. ָ��  5. ����  6. ͷ��\n");
			write("7. ����  8. ��  9. ����  10. ����  11. ����\n");
			write("��ѡ��");
		}
		input_to( (: get_subtype :), ob);
		return;
	}
	
	fabao_subtype = order;

	write("\n");
	write("���趨Ӣ�� id ��");
	input_to( (: get_id :), ob ); 
}


int check_legal_id(string id)
{
	int i;
	string	*legalid;
	
	i = strlen(id);
    if( (strlen(id) < 3) || (strlen(id) > 20 ) ) {
		write("�Բ���Ӣ�� id ������ 3 �� 20 ��Ӣ����ĸ��\n");
		return 0;
    }
    while(i--)
    	if( id[i] != ' ' && (id[i]<'a' || id[i]>'z') )  {
    		write("�Բ���Ӣ�� id ֻ����Ӣ����ĸ��\n");
    		return 0;
    	}
    
    legalid = explode(read_file(BANNED_ID), "\n");
    for(i=0; i<sizeof(legalid); i++)   {
    	if( id == legalid[i] )   {
    		write("�Բ������� id ����������˵����š�\n");
    		return 0;
    	}
    }
    
    return 1;
}


int check_legal_name(string name, int max_len)
{
	int i;
	string	*legalname;		//not implemented..may add later
	
	i = strlen(name);
    if( (strlen(name) < 3) || (strlen(name) > max_len ) ) {
    	write( sprintf("�Բ��𣬷����������ֱ����� 2 �� %d �������֡�\n",
    	 max_len/2) );
		return 0;
    }
    while(i--)   {
    	if( name[i]<=' ' )   {
    		write("�Բ��𣬷����������ֲ����ÿ�����Ԫ��\n");
    		return 0;
    	}
    	if( i%2==0 && !is_chinese(name[i..<0]) )  {
    		write("�Բ��������á����ġ�������ȡ���֡�\n");
    		return 0;
    	}
    }
   
    return 1; 
}


void get_id(string arg, object ob)
{
	arg = lower_case(arg);
	if( !check_legal_id(arg) )   {
		write("���趨Ӣ�� id ��");
		input_to( (: get_id :), ob ); 
		return;
	}
	
	fabao_id = arg;
	
	write("\n");
	write("���趨��������");
	input_to( (: get_name :), ob);
}

void get_name(string arg, object ob)
{
	string  arg_old;

	arg_old = arg;
        arg = replace_string(arg, "$BLK$", "");
        arg = replace_string(arg, "$RED$", "");
        arg = replace_string(arg, "$GRN$", "");
        arg = replace_string(arg, "$YEL$", "");
        arg = replace_string(arg, "$BLU$", "");
        arg = replace_string(arg, "$MAG$", "");
        arg = replace_string(arg, "$CYN$", "");
        arg = replace_string(arg, "$WHT$", "");
        arg = replace_string(arg, "$HIR$", "");
        arg = replace_string(arg, "$HIG$", "");
        arg = replace_string(arg, "$HIY$", "");
        arg = replace_string(arg, "$HIB$", "");
        arg = replace_string(arg, "$HIM$", "");
        arg = replace_string(arg, "$HIC$", "");
        arg = replace_string(arg, "$HIW$", "");
        arg = replace_string(arg, "$NOR$", "");

	if( !check_legal_name(arg, 8) )  {
		write("���趨��������");
		input_to( (: get_name :), ob);
		return;
	}

	arg = arg_old;

        arg = replace_string(arg, "$BLK$", BLK);
        arg = replace_string(arg, "$RED$", RED);
        arg = replace_string(arg, "$GRN$", GRN);
        arg = replace_string(arg, "$YEL$", YEL);
        arg = replace_string(arg, "$BLU$", BLU);
        arg = replace_string(arg, "$MAG$", MAG);
        arg = replace_string(arg, "$CYN$", CYN);
        arg = replace_string(arg, "$WHT$", WHT);
        arg = replace_string(arg, "$HIR$", HIR);
        arg = replace_string(arg, "$HIG$", HIG);
        arg = replace_string(arg, "$HIY$", HIY);
        arg = replace_string(arg, "$HIB$", HIB);
        arg = replace_string(arg, "$HIM$", HIM);
        arg = replace_string(arg, "$HIC$", HIC);
        arg = replace_string(arg, "$HIW$", HIW);
        arg = replace_string(arg, "$NOR$", NOR);
	
	fabao_name = arg + NOR;
	
	write("\n");
	write("������������");
	input_to( (: get_desc :), ob);
}

void get_desc(string arg, object ob)
{
	if( !check_legal_name(arg, 40) )  {
		write("������������");
		input_to( (: get_desc :), ob);
		return;
	}
	
	fabao_desc = arg;
	
	if( fabao_type == "weapon" )
		build_weapon(ob);	
	else if( fabao_type == "armor" )
		build_armor(ob);	
	// may have more later
}

void build_weapon(object ob)
{
	object newob;
	string weapon_dir, ob_file;
	string *id_list, *t_list;
	int rev;
	
	newob = new("/obj/fabao");
	if(!newob)
		return;
		
	seteuid(fabao_id);
	rev = export_uid(newob);
	seteuid(getuid());

	newob->set("value", 1);
	newob->set("no_get", 1);	
	newob->set("no_sell", 1);	
	newob->set("no_drop", 1);	
	newob->set("no_put", 1);	
	
	weapon_dir = "/d/obj/weapon/";
	newob->set("weapon_prop/damage", 1);
	newob->set("flag", TWO_HANDED);
	switch( fabao_subtype )   {
		case 1:
			ob_file = weapon_dir + "axe/bigaxe";
			break;
		case 2:
			ob_file = weapon_dir + "blade/blade";
			break;
		case 3:
			ob_file = weapon_dir + "fork/gangcha";
			break;
		case 4:
			ob_file = weapon_dir + "hammer/hammer";
			break;
		case 5:
			ob_file = weapon_dir + "mace/ironmace";
			break;
		case 6:
			ob_file = weapon_dir + "spear/gangqiang";
			break;
		case 7:
			ob_file = weapon_dir + "staff/muzhang";
			break;
		case 8:
			ob_file = weapon_dir + "stick/qimeigun";
			break;
		case 9:
			ob_file = weapon_dir + "sword/changjian";
			break;
		case 10:
			ob_file = weapon_dir + "whip/pibian";
			break;
	}

	newob->set_default_object( ob_file );
	
	newob->set("long", fabao_desc);
	id_list = ({ fabao_id });
	t_list = explode( fabao_id, " ");
	if( sizeof(t_list) > 1 )   {
		id_list += t_list;
	}
	newob->set_name( fabao_name, id_list ); 

	// set owner of fabao
	newob->set("owner_id", getuid(ob));
	newob->set("series_no", "1");
	newob->set("default_file", ob_file);


    newob->save();	

	ob->add("max_force", -50);
	ob->add("max_mana", -50);
	ob->add("force", -200);
	ob->add("mana", -200);

	ob->set("fabao/weapon",  newob->query("series_no"));

	newob->setup();
	newob->move(ob);

	return;
}

void build_armor(object ob)
{
	object	newob;
	string	armor_dir, ob_file;
	string	*id_list, *t_list;
	int		rev;

	newob = new("/obj/fabao");
	if(!newob)
		return;
	
	seteuid(fabao_id);
	rev = export_uid(newob);
	seteuid(getuid());

	newob->set("value", 1);
	newob->set("no_get", 1);	
	newob->set("no_sell", 1);	
	newob->set("no_drop", 1);	
	newob->set("no_put", 1);	

	armor_dir = "/d/obj/";
	newob->set("armor_prop/armor", 1);		
	newob->set("armor_prop/dodge", 0);		
	newob->set("armor_prop/spells", 0);
	// anything else need to be set?
	
	switch( fabao_subtype )   {
	
	// Add ob_file if you can find the same kind of file
		case 1:
			ob_file = armor_dir + "armor/tenjia";
			break;
		case 2:
			ob_file = armor_dir + "cloth/buxie";
			break;
		case 3:
			ob_file = armor_dir + "cloth/linen";
			break;
		case 4:
			write("�Բ�����ʱ���������ַ�����\n");
			destruct(newob);
			return;
			break;
		case 5:
			write("�Բ�����ʱ���������ַ�����\n");
			destruct(newob);
			return;
			break;
		case 6:
			ob_file = armor_dir + "cloth/hat";
			break;
		case 7:
			write("�Բ�����ʱ���������ַ�����\n");
			destruct(newob);
			return;
			break;
		case 8:
			write("�Բ�����ʱ���������ַ�����\n");
			destruct(newob);
			return;
			break;
		case 9:
			write("�Բ�����ʱ���������ַ�����\n");
			destruct(newob);
			return;
			break;
		case 10:
			write("�Բ�����ʱ���������ַ�����\n");
			destruct(newob);
			return;
			break;
		case 11:
			write("�Բ�����ʱ���������ַ�����\n");
			destruct(newob);
			return;
			break;
	}
	
	newob->set_default_object( ob_file );
	
	newob->set("long", fabao_desc);
	id_list = ({ fabao_id });
	t_list = explode( fabao_id, " ");
	if( sizeof(t_list) > 1 )   {
		id_list += t_list;
	}
	newob->set_name( fabao_name, id_list ); 

	// set owner of fabao
	newob->set("owner_id", getuid(ob));
	if( !ob->query("fabao/armor1") )
		newob->set("series_no", "2");
	else if( !ob->query("fabao/armor2") )
		newob->set("series_no", "3");
	newob->set("default_file", ob_file);

    newob->save();	
	   write("Error" + getuid(newob) + "\n");

	ob->add("max_force", -50);
	ob->add("max_mana", -50);
	ob->add("force", -200);
	ob->add("mana", -200);
	
	if( !ob->query("fabao/armor1") )
		ob->set("fabao/armor1",  newob->query("series_no"));
	else if( !ob->query("fabao/armor2") )
		ob->set("fabao/armor2",  newob->query("series_no"));
	
	newob->setup();
	newob->move(ob);
	
	return;
}
