// Update by aeddy@2002/12/05

#define SOS_DIR       "/data/"
#define SOS_FILENAME  "sos"

#include <command.h>

inherit F_CLEAN_UP;
inherit F_SAVE;

mapping *notes;
int confirm(string yn, object me);

string query_save_file()
{
    return SOS_DIR + SOS_FILENAME ;
}

mixed query(string arg)
{
    if (arg && arg=="channel_id")
        return  "��Ⱦ���";
    return 0;
}

void done_post(object me, mapping note, string text)
{
	int i;
	object where;
	note["msg"] = text;
	i = sizeof(notes);
	where = environment(me);

	for( ; i > 0; i-- ) 
	if( notes[i-1]["author"] == me->query("id") ) break;
	if( !pointerp(notes) || i > 0 )
	if(!sizeof(notes)) notes = ({ note });
	else {
	notes[i-1]["title"] = note["title"];
	notes[i-1]["author"] = note["author"];
	notes[i-1]["msg"] = note["msg"];
	notes[i-1]["time"] = note["time"];
	notes[i-1]["solve"] = "";
	notes[i-1]["solve_id"] = "";
	} else
	notes += ({ note });

	CHANNEL_D->do_channel(this_object(), "sys",
	log_id(me)+"��["+MISC_D->find_place(where)+COLOR_D->clean_color(where->query("short")) +
"]д��һ��"HIR"SOS"NOR WHT"�����Ϣ������\n"NOR);
        log_file("static/sos", sprintf("%s��д��һ��sos��Ϣ ʱ���ڣ�[%s]\n", log_id(me), log_time() ));

	tell_object(me, WHT "�����ϡ������Ϣ�Ѿ����ӵ���ʦ֪ͨ�����\n");
	tell_object(me, WHT "��ʦ���ڴ���������ң���ȴ�������\n");
	tell_object(me, WHT "���һ��ʱ��������sos read�鿴�Ƿ񱻽����\n" NOR);
	save();
	return;
}

void list_bug(object me)
{
	int i;
	string str,s;

	if (sizeof(notes)<1) {
		write("û�˷��� sos ����źš�\n");
	return;
	} 

	s = sprintf("����Ѿ�����δ�����sos�б�����(��Ҫ�쿴�ܱ����� sos list ):\n"
      "������������������������������������������������������������������������������\n");
	for( i = 0; i<sizeof(notes); i++){
	if(notes[i]["solve_id"]=="") {
	str = sprintf("[%2d] %-40s%10s [%s] \n",
       i+1, notes[i]["title"], notes[i]["solve_id"]==""?"��δ�ظ�":"By "+notes[i]["solve_id"],
       BJTIME_CMD->chinese_time(7, ctime(notes[i]["time"])) );
	s = s + str;
	}
	}
	me->start_more(s);                
}

void list_bug_all(object me)
{
	int i;
	string str,s;

	if (sizeof(notes)<1) {
		write("û�˷��� sos �����źš�\n");
	return;
	} 

	s = sprintf("����Ѿ������� sos �б�����:\n"
      "������������������������������������������������������������������������������\n");
	for( i = 0; i<sizeof(notes); i++){
	str = sprintf("[%d] %-40s %10s [%s] \n",
	i+1, notes[i]["title"], notes[i]["solve_id"]==""?"��δ�ظ�":"By "+notes[i]["solve_id"],
       BJTIME_CMD->chinese_time(7, ctime(notes[i]["time"])) );
	s = s + str;
	}
	me->start_more(s);                
}

void do_read(object me, int i) 
{
	string s;
	if( i > sizeof(notes) || i < 1) {
		write("�޴˱�ţ�����\n");
	return;
	}

	s = sprintf("(%d) %-50s [%s]\n"
      "������������������������������������������������������������������������������\n"
      "%s\n"
      U"�������:[ %s ]\n"NOR
      CYN"%s\n"NOR,
	i, notes[i-1]["title"], BJTIME_CMD->chinese_time(7, ctime(notes[i-1]["time"])), 
	notes[i-1]["msg"], notes[i-1]["solve_id"]==""?"��δ�ظ�":"By "+notes[i-1]["solve_id"], 
	notes[i-1]["solve"] );
	me->start_more(s);
}

int search_id(string id)
{
	int i;
	if( !(i = sizeof(notes)) ) return 0;
	for( ; i > 0; i-- ) 
	if( notes[i-1]["author"] == id ) break;
	return i;
}

void done_re(object me, int i, string text)
{
	notes[i-1]["solve"] = text;
	notes[i-1]["solve_id"] = me->query("id");
	save();
	write("�� sos ��Ϣ�ѱ�־Ϊ�����\n");
	return;
}

int do_re(object me, int i)
{
	if( i > sizeof(notes) || i < 1) {
		write("�޴˱�ţ�����\n");
		return 0;
	} 

	if ( notes[i-1]["solve_id"]!="" ) {
		write(notes[i-1]["solve_id"]+"�Ѿ���־����\n");
	return 1;
	}

	write("��������Ĵ��������\n");
	me->edit( (: done_re, me,i :) );
	return 1;
}

int main(object me, string arg)
{
    mapping note;
    object where;
    string s, str,arg1;
    int i,arg2;
    restore();

	if (!arg) {
	if(wiz_level(me)) {
         list_bug_all(me);
	} else {
         write(HIG"\n�����Ķ���ʹ��sos read��ÿ����ֻ����дһ��SOS��Ϣ\n"NOR);
         write(HIG"\n����Ѿ���д����Ϣ��ѡ�� "HIR"Y"HIG" ����������ǰд����SOS��Ϣ\n"NOR);
         write(HIG"\n��ȷ��Ҫдһ��SOS��Ϣ��ȷ��������"HIR"Y"HIC"�����������������˳���\n"NOR);

         input_to((: confirm :), me);
	}
	return 1;
	} 

	if( sscanf(arg, "%s %s", s, arg1) == 2 ) {
	if( !wiz_level(me) ) return notify_fail("��ʽ���ԣ�����ʹ�÷�������� help sos \n");
	if( s != "re" ) return notify_fail("��ʽ���ԣ�����ʹ�÷�������� help sos \n");

	i = search_id(arg1);
	if( i > 0 ) { 
	do_re( me, i );
	return 1;
	}
	}

	if( sscanf(arg, "%s %d", s, arg2) == 2 ) {
	if( !wiz_level(me) ) return notify_fail("��ʽ���ԣ�����ʹ�÷�������� help sos \n");
	if ( s != "re" ) return notify_fail("��ʽ���ԣ�����ʹ�÷�������� help sos \n");
	do_re( me, arg2 ); 
	return 1;
	}

	if ( sscanf(arg, "%s", s) == 1 ) 
	switch(arg){
	case "read":       
		if( !(i = sizeof(notes)) )
			return notify_fail("��û�������� sos ���У�\n");
		else {
			i = search_id( me->query("id") );
			do_read(me,i);
		}
		break;

	case "list":
		if( !wiz_level(me) ) return notify_fail("��ʽ���ԣ�����ʹ�÷�������� help sos \n");
		list_bug_all(me);
		break;

	case "del":
		if( !wiz_level(me) ) return notify_fail("��ʽ���ԣ�����ʹ�÷�������� help sos \n");
		if( !(i = sizeof(notes)) ) return notify_fail("û�˷��� sos ����źš�\n");
		for( ; i > 0; i-- ) 
		if( "" != notes[i-1]["solve_id"] ) {
		printf("%s�� sos �����ѱ�ɾ��������\n", notes[i-1]["author"]);
		if( sizeof(notes) == 1 ) notes = ({});
			else if(i==1) notes = notes[1..sizeof(notes)-1];
			else if( i == sizeof(notes) ) notes = notes[0..sizeof(notes)-2];
			else notes = notes = notes[0..i-2] + notes[i..sizeof(notes)-1];
		}
		save();
		break;

	case "re":
		if( !wiz_level(me) ) return notify_fail("��ʽ���ԣ�����ʹ�÷�������� help sos \n");
		return notify_fail("��ʽ: sos re <��Ż����id>\n");
		break;

		default:
		if( !wiz_level(me) ) return notify_fail("��ʽ���ԣ�����ʹ�÷�������� help sos \n");
		if( sscanf(arg, "%d", i) == 1 )
			do_read( me, i );
		else if( sscanf( arg, "%s", str ) == 1 ) {
			i = search_id(str);
			if( i == 0 ) return notify_fail("�޴���ҷ����� sos ������Ϣ��\n");
			do_read( me, i );
			}
		}
		else return notify_fail("��ʽ���ԣ�����ʹ�÷�������� help sos \n");
	return 1;
}

int confirm(string yn, object me)
{
    mapping note;
    object where;
    string s, str,arg1;
    int i,arg2;
    restore();

	if( upper_case(yn) == "Y" ) {

	if(!wiz_level(me)){
	tell_object(me, CYN "������" HIY MUD_NAME NOR CYN "�������������ͣ�ͻȻ����һֻ����ĳ�������������\n" NOR);
	tell_object(me, CYN "��Ͻ�����ʦ�Ƿ������������źţ��ӣϣӣ�����\n" NOR);
	where = environment(me);
	if (!where ) 
	s=sprintf("%s����",log_id(me));
	else
	s=sprintf("%s��[%s]����", log_id(me), (string)where->query("short"));

//	s=sprintf("%s��%s(%s.c)����", log_id(me), (string)where->query("short"),
//	(string)file_name(where));
	note = allocate_mapping(6);
	note["title"] = s;
	note["author"] = me->query("id"); 
	note["time"] = time();
	note["solve"] = "";
	note["solve_id"] = "";
	me->edit( (: done_post, me, note :) );
	} else {
	list_bug(me);
	}
	} else {
	write(HIW"����������дSOS��Ϣ��������\n"NOR);
	return 1;
	}
}

int help(object me)
{
    if (!wiz_level(me) )
 write(@HELP

ָ���ʽ : 
           sos
           sos read
���ָ�������ϵͳ����bugʱ������ʦ������
����������ϵͳ����ʾ������� bug �����������������Ӧ�ý� bug
���ֵ������ϵͳ����ʾ������ϸ�ؽ���˵�����Ա���ʦ�޸ĸ� bug��
ÿ�����ֻ����һ�� sos���µ� sos ��������ǰ�����롣
������ sos read �Ķ��Լ������� sos��
HELP
 );
    else 
 write(@HELP
ָ���ʽ : 
           sos
           sos <��������id>
           sos list
           sos del
           sos re <��������id>
���ָ����Ը�����ʦ������������ bug �б�sos �� sos list �Ĺ���һ����
���ǽ����е� bug ��Ϣ�����б��������� sos ������ݲ����Ĳ�ͬ������ʾ
��Ӧ������Ӧ��ҵ� bug ����ϸ��Ϣ��sos solve������־ĳ��bug�Ѿ�������ˡ�
sos del ��ɾ�������Ѿ���־Ϊ����˵� bug��
HELP
 );
    return 1;
}
