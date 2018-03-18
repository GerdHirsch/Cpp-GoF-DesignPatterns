/*
 * Kit.h
 *
 *  Created on: 18.03.2018
 *      Author: Gerd
 */

#ifndef KIT_H_
#define KIT_H_

/*
	Ein Template, das den Kit zwischen dem Subject und seinen Clients
	realisiert, taugt für subjects, von denen man typischer weise nur
	eines kennt und sich bei dem anmeldet, die operations-aufrufe von
	update sind fest verdrahtet,
	es gibt keine möglichkeit sich bei verschiedenen Subjects
	mit dem selben interface anzumelden und die subjects zu unterscheiden
*/
template < typename C >
class Kit : public Observer {
public:
	Kit(C& implementation, Subject& subject):Observer(subject),
		implementation(implementation){

	}
	virtual ~Kit(){
		std::cout << "~Kit()" << std::endl;
	}

  void update(std::string& subjectName, int callCount){
      implementation.update(subjectName, callCount);
  }

private:
    C& implementation;
};




#endif /* KIT_H_ */
