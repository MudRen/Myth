// rewritten by vikee 
// 2000.11

inherit NPC;

#include <ansi.h>
#include <login.h>
int  do_sm();
int  do_dispose(string arg);
int  do_upgrade(string arg);
int  do_list();
int  do_cost(string arg);

void get_type(string arg, object ob);
void get_subtype(string arg, object ob);
void get_gender(string arg,object ob);
void get_id(string arg, object ob);
void get_name(string arg, object ob);
void get_desc(string arg, object ob);
void get_unit(string arg, object ob);
void build_pet(object ob);
int check_legal_name(string name, int max_len);
int check_legal_id(string name);
void confirm_dispose(string arg, object ob, object fabao_ob);

string* pet_type_name=({
        "��","ţ","��","��","��","��",
        "��","��","��","��","��","��",
        "è","��","ʨ","��","��","��",
        "��","��","��","����",
	});
string* pet_id_surfix=({
	"shu","niu","hu","tu","long","she",
	"ma","yang","hou","ji","gou","zhu",
	"mao","xiong","shi","lang","bao","hu",
	"diao","niao","chong","qilin",
	});
string* pet_unit_name=({
	"ֻ","ͷ","ͷ","ֻ","��","��",
	"ƥ","ͷ","ͷ","ֻ","��","ͷ",
	"ֻ","ͷ","ͷ","ͷ","ƥ","ֻ",
	"ֻ","ֻ","��","ͷ",
	});
void create()
{
  set_name("�ϰ�", ({"boss"}));
  set("title","������ϰ�");
  set("gender", "����");
  set("age", 32);
  set("long","һ���������ص��ϰ塣\n");
  set("attitude", "peaceful");
  setup();
  carry_object("/d/obj/cloth/linen")->wear();
  add_money("coin", 100);

}

void init()
{
  object ob;

  ::init();
  add_action("do_sm", "choose");
  add_action("do_dispose", "dispose");
  add_action("do_list", "list");
  add_action("do_cost", "cost");
  add_action("do_upgrade", "upgrade");
  add_action("do_change_name", "change_name");
  add_action("do_change_id", "change_id");
  add_action("do_change_desc", "change_desc");
  add_action("do_change_unit", "change_unit");

}
void accept_kill(object me)
{       object ob;
        if(is_fighting()) return;
        if( query("called") ) return;

        command("help!");

        ob=present("xunluo guanbing");
        if( !ob) {
                seteuid(getuid());
                ob=new("/d/city/npc/xunluobing");
                ob->move(environment());
        }
        message_vision("\n��Ȼ������������Ѳ�߹ٱ�����$N��һ������ʲô����ɱ��ı��ô��\n\n",me);        

        ob->kill_ob(me);
        ob->set_leader(me);
        me->fight_ob(ob);
        set("called", 1);
        call_out("regenerate", 300);
}
int regenerate()
{
        set("called", 0);
        return 1;
}


int do_sm()
{
	object me = this_player();
		   
	if( me->query("daoxing") < 20000)
		return notify_fail("��ĵ���̫�ͣ����ܻ������\n");
	
	if( me->query("pet")) 
		return notify_fail("���Ѿ�����һͷ�����ˣ����� dispose �黹�����ڵĳ���\n");
		
	write("��Ҫ��������\n");
	write(" 1. ��   2. ţ   3. ��   4. ��  5. ��  6. ��\n");
	write(" 7. ��   8. ��   9. ��  10. �� 11. �� 12. ��\n");
	write("13. è  14. ��  15. ʨ  16. �� 17. �� 18. ��\n");
	write("19. ��  20. ��  21. ��  22. ����\n");
     	write("��ѡ��(q ��ȡ��)");
	input_to( (: get_subtype :), me);
	return 1;
}

void get_subtype(string arg, object ob)
{
    int  order;
   
	if( arg == "q" || arg == "Q" )    return;

    	sscanf(arg, "%d", order);
    
	  if (order <= 0 || order > 22)  {
		
	        write("��Ҫ��������\n");
        	write(" 1. ��   2. ţ   3. ��   4. ��  5. ��  6. ��\n");
    	    	write(" 7. ��   8. ��   9. ��  10. �� 11. �� 12. ��\n");
        	write("13. è  14. ��  15. ʨ  16. �� 17. �� 18. ��\n");
        	write("19. ��  20. ��  21. ��  22. ����\n");
        	write("��ѡ��(q ��ȡ��)");
		input_to( (: get_subtype :), ob);
		return;
	}
	
	ob->set_temp("pet/pet_type",  order);

	write("\n");
	write("���趨������Ա�(���ԣ�1  ����:��)��");
	input_to( (: get_gender :), ob ); 
}

void get_gender(string arg, object ob)
{
	int gender;
        sscanf(arg, "%d", gender);

          if (gender != 0 && gender != 1)  {
        	write("\n");
        	write("���趨������Ա�(���ԣ�1  ����:��)��");
        	input_to( (: get_gender :), ob );
		return;
	    }
	ob->set_temp("pet/pet_gender",gender?"����":"Ů��");

        write("\n");
        write("���趨Ӣ�� id ��");
        input_to( (: get_id :), ob );
}
int check_legal_id(string id)
{
	int i;
	string	*legalid;
  	object ppl;	
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

        ppl = LOGIN_D->find_body(id);
        if(ppl || id=="guest" || id=="new") {
            write("��������������ID��ͬ�ˣ�����");
            return 0;
        }

        if( file_size(sprintf("/data/user/%c/%s",id[0],id)
                    + __SAVE_EXTENSION__) >= 0 ) {
            write("��������Ѿ���������ʹ���ˣ�����");
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
    if( (strlen(name) < 2) || (strlen(name) > max_len ) ) {
    	write( sprintf("�Բ��𣬷��������ֱ����� 1 �� %d �������֡�\n",
    	 max_len/2) );
		return 0;
    }
    while(i--)   {
    	if( name[i]<=' ' )   {
    		write("�Բ��𣬷��������ֲ����ÿ�����Ԫ��\n");
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

	arg = replace_string(arg, " ", "_");	
	ob->set_temp("pet/pet_id",arg+" "+
	pet_id_surfix[ob->query_temp("pet/pet_type")-1]);
	
	write("\n");
	write("����������趨����������ע�⣬���趨������������ϻ�������\n");
	write("������ѡ������ã�������ΪС��, ���־ͻ�ΪС����\n");
	write("���趨��������(�ɼ���ɫ)");
	input_to( (: get_name :), ob);
}

void get_name(string arg, object ob)
{
	string  arg_old;
	
//	arg += "$NOR$";
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

	if( !check_legal_name(arg, 12) )  {
        write("����������趨����������ע�⣬���趨������������ϻ�������\n");
        write("������ѡ������ã�������ΪС��, ���־ͻ�ΪС����\n");
 	    write("���趨��������(�ɼ���ɫ)");
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
	
	ob->set_temp("pet/pet_name", arg );
	
	write("\n");
	write("���������");
	input_to( (: get_desc :), ob);
}

void get_desc(string arg, object ob)
{
	if( !check_legal_name(arg, 60) )  {
		write("���������");
		input_to( (: get_desc :), ob);
		return;
	}

	ob->set_temp("pet/pet_desc",  arg);
	
	write("\n");
	write("���������ʣ�(Return for default)");
	input_to( (: get_unit :), ob);
}


void get_unit(string arg, object ob)
{
	string pet_unit, pet_type;
    if( arg == "" )
       pet_unit = "";
	else if( !check_legal_name(arg, 2) )  {
 	   write("���������ʣ�(Return for defult)");
	   input_to( (: get_unit :), ob);
	   return;
    }
    else
       pet_unit = arg; 
   
	pet_type = ob->query_temp("pet/pet_type");
	ob->set_temp("pet/pet_unit", pet_unit);
	build_pet(ob);	
	// may have more later
}

void build_pet(object ob)
{
	object newob;
	string *id_list, *t_list;
	int rev;
	string msg;
	string pet_type = ob->query_temp("pet/pet_type");
	string pet_id = ob->query_temp("pet/pet_id");
	string pet_name = ob->query_temp("/pet/pet_name");
	string pet_desc = ob->query_temp("pet/pet_desc");
	string pet_unit = ob->query_temp("pet/pet_unit");
 	string base_name= pet_type_name[(int)pet_type - 1];	
	string pet_gender = ob->query_temp("pet/pet_gender");
	newob = new(__DIR__"pet");
	if(!newob)
		return ;
	seteuid(pet_id);
	rev = export_uid(newob);
	seteuid(getuid());

	
	newob->set("weight", 1000);
	
	newob->set("long", pet_desc+"\n"+"����"+ob->query("name")+

        "�ĳ��\n");

	if( pet_unit != "" )
	   newob->set("unit", pet_unit);
	else 
	   newob->set("unit", pet_unit_name[(int)pet_type-1]);
	id_list = ({ pet_id });
	t_list = explode( pet_id, " ");
	if( sizeof(t_list) > 1 )   {
		id_list += t_list;
	}
	pet_name+=base_name+NOR;	
	newob->set_name( pet_name, id_list ); 

	// set owner of pet
	newob->set("owner", ob->query("id"));
	newob->set("series_no", "1");
	newob->set("gender",pet_gender);
	newob->save();
	ob->set("pet/pet_id",pet_id);	
	ob->set("pet/pet_type", base_name);
	ob->set("pet/pet_name", pet_name);
	ob->set("pet/pet_desc", pet_desc);
	ob->set("pet/pet_unit", pet_unit);

	newob->setup();
	msg="$Nת�����ڱ���һֻ"+pet_name+"������\n"+
	    "��ϲ$n������"+pet_name+"���Ժ�$n��Ҫ�úô�����\n";
	message_vision(msg,this_object(),ob);
	if( !newob->move(ob) )
	   newob->move(environment(ob));
	ob->delete_temp("pet");
	ob->save();

	return;
}


int  do_dispose(string arg)
{
   object ob = this_player();
   object pet_ob;
   string pet_id;
    
   if (!ob->query("pet/pet_id"))
      return notify_fail("�㲢û�г������ʲô���֣�\n");
   pet_id=ob->query("pet/pet_id");
   if( !objectp(pet_ob=present(pet_id, ob)) && 
       !objectp(pet_ob=present(pet_id, environment(ob))))
      return notify_fail("��ĳ���û����һ������?\n");
      
   if(pet_ob->query("owner") != ob->query("id")) 
      return notify_fail("��......���������������Ү��\n");
      
   write("��ȷ��Ҫ�������"+pet_ob->query("name")+"(y/n)");
   if (ob->query_temp("pet")==1)
   {
     ob->set_temp("apply/dodge",0);
     ob->set_temp("pet",0);
   }

     
   input_to( (: confirm_dispose :), ob, pet_ob); 
   return 1;
}

void confirm_dispose(string arg, object ob, object pet_ob)
{
   string msg;

   if( arg == "y" || arg == "Y" )  {
	ob->delete("pet");
	msg="$N��Թ�ؿ���$nһ�ۣ�ĬĬ���߽��˺��ݡ�\n";
	message_vision(msg,pet_ob,ob);
	destruct( pet_ob );
//add by yudian
ob->delete_temp("ride/dodge");
   }

   return;
}



int  do_change_name(string arg)
{
   string name, newname;
   object fabao_ob, me=this_player();
  
   if( !arg || arg == "") 
      return notify_fail("���� change_name <����> <��������> ��������\n");
      
   if( sscanf(arg, "%s %s", name, newname) != 2)
      return notify_fail("���� change_name <����> <��������> ��������\n");
   
   if( !objectp(fabao_ob=present(name, me)) )
      return notify_fail("������û���������ﰡ��\n");

   if(!fabao_ob->query("owner_id") || !fabao_ob->query("series_no")) 
      return notify_fail("�Ǹ�������ĳ���Ү��\n");

   
   newname += "$NOR$";      
   arg = newname;
            
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
        
   if( !check_legal_name(arg, 12) )   {
      return 1; 
   }
  
   arg = newname;
    
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
  
   fabao_ob->set("name", arg);
   fabao_ob->save();     
   
   write("�Ķ��ɹ���\n");
   return 1;
}
      
int  do_change_id(string arg)
{
   string name, newname;
   object fabao_ob, me=this_player();
   string *id_list, *t_list;
  
   if( !arg || arg == "") 
      return notify_fail("���� change_id <����> <��Ӣ����> ��������\n");
      
   if( sscanf(arg, "%s %s", name, newname) != 2)
      return notify_fail("���� change_id <����> <��Ӣ����> ��������\n");
   
   if( !objectp(fabao_ob=present(name, me)) )
      return notify_fail("������û��������������\n");

   
   
   if( !check_legal_id( newname ) )		return 1;
  
   newname = replace_string(newname, " ", "_"); 
   fabao_ob->set("id", newname);

   id_list = ({ newname });
   t_list = explode( newname, "_");
   if( sizeof(t_list) > 1 )   {
	  id_list += t_list;
   }
   fabao_ob->set_name( fabao_ob->query("name"), id_list ); 
   fabao_ob->save();
	
   write("�Ķ��ɹ���\n");
   return 1;
}

      
int  do_change_desc(string arg)
{
   string name, newname;
   object fabao_ob, me=this_player();
  
   if( !arg || arg == "") 
      return notify_fail("���� change_desc <����> <������> �������������\n");
      
   if( sscanf(arg, "%s %s", name, newname) != 2)
      return notify_fail("���� change_desc <����> <������> �������������\n");
   
   if( !objectp(fabao_ob=present(name, me)) )
      return notify_fail("������û��������������\n");

   if(!fabao_ob->query("owner_id") || !fabao_ob->query("series_no")) 
      return notify_fail("�Ǹ�������ĳ���Ү��\n");

   
   if( !check_legal_name(newname, 60 ) )		return 1;
   
   fabao_ob->set("long", newname);
   fabao_ob->save();
   
   write("�Ķ��ɹ���\n");
   return 1;
}
      
int  do_change_unit(string arg)
{
   string name, newname;
   object fabao_ob, me=this_player();
  
   if( !arg || arg == "") 
      return notify_fail("���� change_unit <����> <��λ> ��ָ��������λ��\n");
      
   if( sscanf(arg, "%s %s", name, newname) != 2)
      return notify_fail("���� change_unit <����> <��λ> ��ָ��������λ��\n");
   
   if( !objectp(fabao_ob=present(name, me)) )
      return notify_fail("������û��������������\n");

   if(!fabao_ob->query("owner_id") || !fabao_ob->query("series_no")) 
      return notify_fail("�Ǹ����Ƿ���Ү��\n");

   if( fabao_ob->query("equipped") )
      return notify_fail("�������·������ܸ�����\n");

   if( !check_legal_name(newname, 2 ) )		return 1;
   
   fabao_ob->set("unit", newname);
   fabao_ob->save();
   
   write("�Ķ��ɹ���\n");
   return 1;
}
